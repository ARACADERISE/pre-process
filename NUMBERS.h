#include <stdio.h>
#include <stdint.h>

/* Max sizes
    - sm: Signed Maxed
    - um: Unsigned Maxed
        - min ammount of um will always be zero
*/

// int2: signed: min/max
#define sm_int2_min     -2
#define sm_int2_max      2
// unsigned: min/max
#define um_int2_min      0
#define um_int2_max      4

// int4: signed: min/max
#define sm_int4_min     -4
#define sm_int4_max      4
// unsigned: min/max
#define um_int4_min      0
#define um_int4_max      8

// int6: signed: min/max
#define sm_int6_min     -62
#define sm_int6_max      61
// unsigned: min/max
#define um_int6_min      0
#define um_int6_max      63

// int 8: signed: min/max
#define sm_int8_min     -128
#define sm_int8_max      127
// unsigned: min/max
#define um_int8_min      0
#define um_int8_max      255

// int 16: signed: min/max
#define sm_int16_min    -32768
#define sm_int16_max     32767
// unsigned: min/max
#define um_int16_min     0
#define um_int16_max     65535

// int 20: signed: min/max
#define sm_int20_min    -524289
#define sm_int20_max     524287
// unsigned: min/max
#define um_int20_min     0
#define um_int20_max     1048576

// int 24: signed: min/max
#define sm_int24_min    -8388608
#define sm_int24_max     8388607
// unsigned: min/max
#define um_int24_min     0
#define um_int24_max     16177215

// int 28: signed: min/max
#define sm_int28_min   -134217729
#define sm_int28_max    134217728
// unsigned: min/max
#define um_int28_min    0
#define um_int28_max    268435456

// int 30: signed: min/max
#define sm_int30_min   -536870913
#define sm_int30_max    536870912
// unsigned: min/max
#define um_int30_min    0
#define um_int30_max    1073741824

// int 32: signed: min/max
#define sm_int32_min   -2147483648
#define sm_int32_max    2147483647
// unsigned: min/max
#define um_int32_min    0
#define um_int32_max    4294967295

// int 34: signed: min/max
#define sm_int40_min   -549755813889
#define sm_int40_max    549755813887
// unsigned: min/max
#define um_int40_min    0
#define um_int40_max    1099511627776

// int 64: signed: min/max
#define sm_int64_min    -9223372036854775808
#define sm_int64_max     9223372036854775807
// unsigned: min/max
#define um_int64_min     0
#define um_int64_max     18446744073709551615 // Don't really know what would need this big of a number

#define typeof(value); \
if(!(value==0)) {\
    if((value>=sm_int2_min&&!(value>sm_int2_max))||(!(value>um_int2_max))){\
        if(value<=um_int2_max&&value>-1){\
            printf("um_int2_max:%d",value);\
        } else{\
            printf("sm_int2_min:%d",value);\
        }\
    } else if((value>=sm_int4_min&&!(value>sm_int4_max))||(!(value>um_int4_max))) {\
        if(value<=um_int4_max&&value>-1){\
            printf("um_int4_max:%d",value);\
        } else{\
            printf("um_int4_min:%d",value);\
        }\
    } else if((value>=sm_int6_max&&!(value>sm_int4_max))||!(value>um_int6_max)){\
        if(value<=um_int6_max&&value>-1){\
            printf("um_int6_max:%d",value);\
        } else{\
            printf("sm_int6_min:%d",value);\
        }\
    }\
} else {\
    printf("Number %d cannot be detected",value);\
}
