#include <boost/utility/enable_if.hpp>
#include <type_traits>

#include "Table.h"

extern "C" {
#include "postgres.h"
#include "fmgr.h"
#include "lib/stringinfo.h"
#include "utils/builtins.h"
#include "utils/jsonb.h"
}

/**
 * Converts the input value to a json value object and returns it
 *
 * @tparam TypeValue - type input value
 * @param value - input value
 */
template <typename TypeValue>
JsonbValue *toJvValue(
    typename boost::disable_if<std::is_same<TypeValue, DynamicValue>,
                               TypeValue>::type value) {
    JsonbValue *jvValue = (JsonbValue *)palloc(sizeof(JsonbValue));

    if (value == boost::lexical_cast<TypeValue>(NULL)) {
        jvValue->type = jvValue->jbvNull;
    } else if (typeid(TypeValue) == typeid(int) ||
               typeid(TypeValue) == typeid(float) ||
               typeid(TypeValue) == typeid(cpp_dec_float_50)) {
        jvValue = (JsonbValue *)palloc(sizeof(JsonbValue));

        if (boost::math::isnan(value) || boost::math::isinf(value)) {
            value = boost::lexical_cast<TypeValue>(NULL);
        }

        std::string strValue = boost::lexical_cast<std::string>(value);

        jvValue->type = jvValue->jbvNumeric;
        jvValue->val.numeric = DatumGetNumeric(DirectFunctionCall3(
            numeric_in, CStringGetDatum(strValue.c_str()),
            ObjectIdGetDatum(InvalidOid), Int32GetDatum(-1)));
    } else if (typeid(TypeValue) == typeid(std::string)) {
        std::string strValue = boost::lexical_cast<std::string>(value);

        auto cstr = (char *)palloc(sizeof(char) * (strValue.length() + 1));

        memcpy((void *)cstr, (void *)strValue.c_str(),
               sizeof(char) * (strValue.length()));

        cstr[strValue.length()] = '\0';

        jvValue->type = jvValue->jbvString;
        jvValue->val.string.len = static_cast<int>(strValue.length());
        jvValue->val.string.val = cstr;
    } else if (typeid(TypeValue) == typeid(bool)) {
        jvValue->type = jvValue->jbvBool;
        jvValue->val.boolean = boost::lexical_cast<bool>(value);
    } else {
        delete jvValue;
        ereport(ERROR, (errcode(ERRCODE_RAISE_EXCEPTION),
                        errmsg("Type conversion undefined")));
    }

    return jvValue;
}

//! only TypeValue = DynamicValue
template <typename TypeValue>
JsonbValue *toJvValue(
    typename boost::enable_if<std::is_same<TypeValue, DynamicValue>,
                              TypeValue>::type value) {
    if (value.type == DvType::TYPE_NONE || value.type == DvType::TYPE_OTHER)
        return toJvValue<int>(NULL);
    else if (value.type == DvType::TYPE_BOOLEAN)
        return toJvValue<bool>(static_cast<bool>(value));
    else if (value.type == DvType::TYPE_STRING)
        return toJvValue<std::string>(
            boost::any_cast<std::string>(value.value));
    else if (value.type == DvType::TYPE_DATE ||
             value.type == DvType::TYPE_TIME ||
             value.type == DvType::TYPE_DATETIME)
        return toJvValue<int>(
            static_cast<int>(boost::any_cast<cpp_dec_float_50>(value.value)));
    else
        return toJvValue<cpp_dec_float_50>(
            boost::any_cast<cpp_dec_float_50>(value.value));
}

/**
 * Converts the input dict json value to map object and returns it
 *
 * @tparam TypeKey - type key in map
 * @tparam TypeValue - type value in map
 * @param JObject - dict json object
 */
template <typename TypeKey, typename TypeValue>
typename boost::disable_if<std::is_same<TypeValue, DynamicValue>,
                           std::map<TypeKey, TypeValue>>::type
convertJsonbToMap(Jsonb *JObject) {
    StringInfo out = makeStringInfo();
    char *strJObject = JsonbToCString(out, &JObject->root, 10);

    JsonbIterator *it = JsonbIteratorInit(&JObject->root);
    JsonbIteratorToken r;
    JsonbValue v;
    std::map<TypeKey, TypeValue> res;

    r = JsonbIteratorNext(&it, &v, true);

    if (r != WJB_BEGIN_OBJECT) {
        auto msg =
            (boost::format("%s must be object {key, value}") % strJObject)
                .str()
                .c_str();

        ereport(ERROR, (errcode(ERRCODE_RAISE_EXCEPTION), errmsg(msg)));
    }

    while ((r = JsonbIteratorNext(&it, &v, true)) != WJB_END_OBJECT) {
        TypeKey key;
        TypeValue val;

        if (r == WJB_KEY) {
            std::string strkey(v.val.string.val, v.val.string.len);

            try {
                key = boost::lexical_cast<TypeKey>(strkey);

                r = JsonbIteratorNext(&it, &v, true);
            } catch (boost::bad_lexical_cast &e) {
                auto msg = (boost::format("%1%: key %2% must be (%3%) string") %
                            strJObject % strkey % typeid(TypeKey).name())
                               .str()
                               .c_str();

                ereport(ERROR, (errcode(ERRCODE_RAISE_EXCEPTION), errmsg(msg)));
            }

            if (r == WJB_VALUE) {
                if (v.type == v.jbvString) {
                    std::string strValue(v.val.string.val, v.val.string.len);
                    res[key] = boost::lexical_cast<TypeValue>(strValue);
                } else if (v.type == v.jbvNumeric) {
                    float8 numValue = DatumGetFloat8(DirectFunctionCall1(
                        numeric_float8, NumericGetDatum(v.val.numeric)));
                    res[key] = boost::lexical_cast<TypeValue>(numValue);
                } else if (v.type == v.jbvNull) {
                    res[key] = boost::lexical_cast<TypeValue>(NULL);
                } else if (v.type == v.jbvBool) {
                    res[key] = boost::lexical_cast<TypeValue>(v.val.boolean);
                } else {
                    ereport(ERROR,
                            (errcode(ERRCODE_RAISE_EXCEPTION),
                             errmsg("Type value of object Jsonb undefined")));
                }
            }
        }
    }

    return res;
}

//! only TypeValue = DynamicValue
template <typename TypeKey, typename TypeValue>
typename boost::enable_if<std::is_same<TypeValue, DynamicValue>,
                          std::map<TypeKey, TypeValue>>::type
convertJsonbToMap(Jsonb *JObject) {
    StringInfo out = makeStringInfo();
    char *strJObject = JsonbToCString(out, &JObject->root, 10);

    JsonbIterator *it = JsonbIteratorInit(&JObject->root);
    JsonbIteratorToken r;
    JsonbValue v;
    std::map<TypeKey, DynamicValue> res;

    r = JsonbIteratorNext(&it, &v, true);

    if (r != WJB_BEGIN_OBJECT) {
        auto msg =
            (boost::format("%s must be object {key, value}") % strJObject)
                .str()
                .c_str();

        ereport(ERROR, (errcode(ERRCODE_RAISE_EXCEPTION), errmsg(msg)));
    }

    while ((r = JsonbIteratorNext(&it, &v, true)) != WJB_END_OBJECT) {
        TypeKey key;
        DynamicValue val;

        if (r == WJB_KEY) {
            std::string strkey(v.val.string.val, v.val.string.len);

            try {
                key = boost::lexical_cast<TypeKey>(strkey);
                r = JsonbIteratorNext(&it, &v, true);
            } catch (boost::bad_lexical_cast &e) {
                auto msg = (boost::format("%1%: key %2% must be (%3%) string") %
                            strJObject % strkey % typeid(TypeKey).name())
                               .str()
                               .c_str();

                ereport(ERROR, (errcode(ERRCODE_RAISE_EXCEPTION), errmsg(msg)));
            }

            if (r == WJB_VALUE) {
                if (v.type == v.jbvString) {
                    std::string strValue(v.val.string.val, v.val.string.len);
                    res[key] = {DvType::TYPE_STRING, strValue};
                } else if (v.type == v.jbvNumeric) {
                    float8 numValue = DatumGetFloat8(DirectFunctionCall1(
                        numeric_float8, NumericGetDatum(v.val.numeric)));
                    res[key] = {DvType::TYPE_NUMBER,
                                cpp_dec_float_50(numValue)};
                } else if (v.type == v.jbvNull) {
                    res[key] = {DvType::TYPE_NONE, cpp_dec_float_50(0)};
                } else if (v.type == v.jbvBool) {
                    res[key] = {DvType::TYPE_BOOLEAN,
                                cpp_dec_float_50(v.val.boolean)};
                } else {
                    ereport(ERROR,
                            (errcode(ERRCODE_RAISE_EXCEPTION),
                             errmsg("Type value of object Jsonb undefined")));
                }
            }
        }
    }

    return res;
}

/**
 * Converts the input map object to dict json value and returns it
 *
 * @tparam TypeKey - type key in input map
 * @param value - map where type of value is DynamicValue
 */
template <typename TypeKey>
JsonbValue *convertMapDynamicValueToJsonbValue(
    std::map<TypeKey, DynamicValue> value) {
    JsonbParseState *parseState = NULL;
    JsonbValue *res = pushJsonbValue(&parseState, WJB_BEGIN_OBJECT, NULL);

    BOOST_FOREACH (auto &m_pair, value) {
        auto jvKey = (JsonbValue *)palloc(sizeof(JsonbValue));
        char *cstr;

        std::string strKey = boost::lexical_cast<std::string>(m_pair.first);
        cstr = (char *)palloc(sizeof(char) * (strKey.length() + 1));

        memcpy((void *)cstr, (void *) strKey.c_str(),
               sizeof(char) * (strKey.length()));

        cstr[strKey.length()] = '\0';

        jvKey->type = jvKey->jbvString;
        jvKey->val.string.len = static_cast<int>(strKey.length());
        jvKey->val.string.val = cstr;

        //! add key and value
        pushJsonbValue(&parseState, WJB_KEY, jvKey);
        pushJsonbValue(&parseState, WJB_VALUE,
                       toJvValue<DynamicValue>(m_pair.second));
    }

    pushJsonbValue(&parseState, WJB_END_OBJECT, NULL);

    return res;
}

extern "C" {

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

//! register a postgresql function and define it
PG_FUNCTION_INFO_V1(calculation_row_values);

Datum calculation_row_values(PG_FUNCTION_ARGS) {
    Jsonb *jNameColumns = PG_GETARG_JSONB(0);
    Jsonb *jTypeColumns = PG_GETARG_JSONB(1);
    Jsonb *jFormulaColumns = PG_GETARG_JSONB(2);
    Jsonb *jRowValues = PG_GETARG_JSONB(3);

    std::map<unsigned int, std::string> cameColumns =
        convertJsonbToMap<unsigned int, std::string>(jNameColumns);
    std::map<unsigned int, int> typeColumns =
        convertJsonbToMap<unsigned int, int>(jTypeColumns);
    std::map<unsigned int, std::string> formulaColumns =
        convertJsonbToMap<unsigned int, std::string>(jFormulaColumns);
    std::map<unsigned int, DynamicValue> rowValues =
        convertJsonbToMap<unsigned int, DynamicValue>(jRowValues);

    try {
        //! make calculations
        Table(cameColumns, typeColumns, formulaColumns)
            .recalculationRowValues(rowValues);
    } catch (std::exception &e) {
        auto msg = boost::format("Calculation error: %s") % e.what();

        ereport(ERROR,
                (errcode(ERRCODE_RAISE_EXCEPTION), errmsg(msg.str().c_str())));
    }

    auto jv_calc_values =
        convertMapDynamicValueToJsonbValue<unsigned int>(rowValues);

    Jsonb *result = JsonbValueToJsonb(jv_calc_values);

    PG_RETURN_JSONB(result);
}
}
