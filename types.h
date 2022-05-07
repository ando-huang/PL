#include <cstdint>

class TypedValue
{
    enum types
    {
        Integer,
        Unsigned_Integer,
        Float,
        Unsigned_Floating,
        String,
        Vector,
    };

    struct Type
    {
        int t;
    };

    struct Value {
        union {
            uint32_t int_val;
            uint32_t uint_val;
            uint32_t float_val;
            uint32_t u_float_val;
            char* string_val;
            char* vector_base_val;
        };
    };

    Type type;
    Value value;

public:

static uint32_t getValue();

private:

static Type getType();
static int interpret_int();
static uint32_t interpret_unsigned_int();
static char* interpret_string();
static char* interpret_vector();
};
