CREATE OR REPLACE FUNCTION calculation_row_values(jsonb, jsonb, jsonb, jsonb) RETURNS jsonb
AS '$libdir/table_engine_db', 'calculation_row_values'
LANGUAGE C IMMUTABLE STRICT;