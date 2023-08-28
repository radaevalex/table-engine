#ifndef TABLE_ENGINE_ENGINE_H
#define TABLE_ENGINE_ENGINE_H

#include <boost/algorithm/string.hpp>
#include <boost/any.hpp>
#include <boost/foreach.hpp>
#include <boost/format.hpp>
#include <boost/generator_iterator.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/python.hpp>
#include <datetime.h>
#include <boost/python/to_python_converter.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <set>
#include <string>
#include <vector>

using boost::multiprecision::cpp_dec_float_50;
namespace py = boost::python;
typedef std::map<std::string, std::string> Column;

//! Constants

static std::string ACII_LOWERCASE = "abcdefghijklmnopqrstuvwxyz";

enum DvType {
    TYPE_NUMBER = 1,
    TYPE_STRING,
    TYPE_BOOLEAN,
    TYPE_TIME,
    TYPE_DATE,
    TYPE_DATETIME,
    TYPE_NONE,
    TYPE_OTHER
};

/**
 * structure for storing values of various types
 */
class DynamicValue {
   public:
    DvType type;
    boost::any value;

    DynamicValue(){};

    DynamicValue(DvType _type, boost::any _value)
        : type(_type), value(_value){};

    operator bool() const {
        if (this->type == DvType::TYPE_STRING) {
            return boost::lexical_cast<bool>(
                boost::any_cast<std::string>(this->value));
        } else {
            return boost::lexical_cast<bool>(
                boost::any_cast<cpp_dec_float_50>(this->value));
        }
    }

    bool operator==(const DynamicValue &y) {
        if (this->type == DvType::TYPE_STRING &&
            y.type == DvType::TYPE_STRING) {
            return boost::any_cast<std::string>(this->value) ==
                   boost::any_cast<std::string>(y.value);
        } else if (this->type == DvType::TYPE_STRING ||
                   y.type == DvType::TYPE_STRING) {
            return false;
        } else {
            return boost::any_cast<cpp_dec_float_50>(this->value) ==
                   boost::any_cast<cpp_dec_float_50>(y.value);
        }
    }

    bool operator<(const DynamicValue &y) {
        if (this->type == DvType::TYPE_STRING &&
            y.type == DvType::TYPE_STRING) {
            return boost::any_cast<std::string>(this->value) <
                   boost::any_cast<std::string>(y.value);
        } else if (this->type == DvType::TYPE_STRING) {
            return false;
        } else if (y.type == DvType::TYPE_STRING) {
            return true;
        } else {
            return boost::any_cast<cpp_dec_float_50>(this->value) <
                   boost::any_cast<cpp_dec_float_50>(y.value);
        }
    }

    bool operator&&(const DynamicValue &y) {
        return static_cast<bool>(*this) && static_cast<bool>(y);
    }

    bool operator||(const DynamicValue &y) {
        return static_cast<bool>(*this) || static_cast<bool>(y);
    }

    bool operator!=(const DynamicValue &y) { return !((*this) == y); }

    bool operator<=(const DynamicValue &y) {
        return (*this) < y || (*this) == y;
    }

    bool operator>(const DynamicValue &y) { return !((*this) <= y); }

    bool operator>=(const DynamicValue &y) { return !((*this) < y); }
};

/**
 * struct for store value in row and its representations
 */
struct CellValue {
    DynamicValue value;
    std::string repr;
    boost::optional<std::string> color = boost::none;
};

//! Functions

/**
 * Returns a grouped map according to the key function.
 * Key in map is the value from the key function.
 * Value in map is the group according to value from the key function.
 *
 * @tparam A - Type of value from the key function
 * @tparam B - Type of value in Array
 * @param arr - Array to be grouped
 * @param key - A function for computing the group category for each element.
 */
template <typename A, typename B>
static std::map<B, std::vector<A>> group_by(std::vector<A> &arr,
                                            std::function<B(A)> key) {
    std::map<B, std::vector<A>> groups;

    BOOST_FOREACH (auto &elem, arr) {
        if (groups.find(key(elem)) == groups.end()) {
            std::vector<A> group = {elem};
            groups[key(elem)] = group;
        } else {
            groups[key(elem)].push_back(elem);
        }
    }

    return groups;
}

/**
 * Returns the swaped map
 *
 * @tparam T1 - Type of key in map
 * @tparam T2 - Type of value in map
 * @param oldMap - Map that need swap
 */
template <class T1, class T2>
static std::map<T2, T1> swapPairs(std::map<T1, T2> oldMap) {
    std::map<T2, T1> swapMap;
    for (auto &&item : oldMap) {
        swapMap.emplace(item.second, item.first);
    }
    return swapMap;
};

/**
 * Returns the result of the comparison
 * @tparam T - Type of values
 * @param lvalue - First value
 * @param rvalue - Second value
 * @param operation - String operation
 */
template <typename T>
static bool cmp(T lvalue, T rvalue, std::string operation) {
    bool value;

    if (operation == "=")
        value = lvalue == rvalue;
    else if (operation == "<>")
        value = lvalue != rvalue;
    else if (operation == "<")
        value = lvalue < rvalue;
    else if (operation == ">")
        value = lvalue > rvalue;
    else if (operation == "<=")
        value = lvalue <= rvalue;
    else if (operation == ">=")
        value = lvalue >= rvalue;
    else if (operation == "and")
        value = static_cast<bool>(lvalue) && static_cast<bool>(rvalue);
    else if (operation == "or")
        value = static_cast<bool>(lvalue) || static_cast<bool>(rvalue);

    return value;
}

/**
 * Check on number string
 * @param str - String
 * @return true if str is number string
 */
static bool is_str_int(const std::string &str) {
    return std::regex_match(str, std::regex("^[(-|+)]?[0-9]+$"));
}

/**
 * Check on number (float) string
 * @param str - String
 * @return true if str is number (float) string
 */
static bool is_str_float(const std::string &str) {
    return std::regex_match(
        str, std::regex("^[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)$"));
}

/**
 * Converts the value to the passed DvType.
 * If it is not possible to convert to the passed type, passed value convert to
 * TYPE_OTHER
 * @param type - passed DvType
 * @param value - passed DynamicValue
 */
static void to_type(DvType type, DynamicValue &value) {
    try {
        if (value.type == DvType::TYPE_OTHER ||
            value.type == DvType::TYPE_NONE) {
            return;
        } else if (value.type == DvType::TYPE_STRING &&
                   (type != DvType::TYPE_STRING)) {
            value.value = boost::lexical_cast<cpp_dec_float_50>(
                boost::any_cast<std::string>(value.value));
        } else if (type == DvType::TYPE_STRING &&
                   (value.type != DvType::TYPE_STRING)) {
            value.value = boost::lexical_cast<std::string>(
                boost::any_cast<cpp_dec_float_50>(value.value));
        } else {
            value.value = value.value;
        }

        value.type = type;
    } catch (std::out_of_range &) {
        value = {DvType::TYPE_OTHER, cpp_dec_float_50(NAN)};
    }
}

/**
 * Iterator that generates letters
 * in the following format: A, B, ... Z, AA, ... ZZ, AAA ..
 * example:
 *     static std::string ACII_LOWERCASE = "abcdefghijklmnopqrstuvwxyz";
 *     letters_generator gen(ACII_LOWERCASE);
 *     boost::generator_iterator_generator<letters_generator>::type letter_it =
 *                                         boost::make_generator_iterator(gen);
 *     letter_it++;
 * @param alphabet - alphabet string
 */
class letters_generator {
   public:
    typedef std::string result_type;

    letters_generator(std::string alphabet) : state({0}), alphabet(alphabet) {}

    std::string operator()() {
        std::string res = "";
        bool incriment = true;

        for (int i = this->state.size() - 1; i >= 0 && incriment; i--) {
            int newStateValue = state[i];

            if (incriment) {
                newStateValue++;
            }

            state[i] = newStateValue % this->alphabet.size();
            incriment = newStateValue >= this->alphabet.size();
        }

        if (incriment) {
            this->state.push_back(0);
        }

        BOOST_FOREACH (auto &index, this->state) {
            res += this->alphabet[index];
        }

        return res;
    }

   private:
    std::vector<int> state;
    std::string alphabet;
};

#endif  // TABLE_ENGINE_ENGINE_H
