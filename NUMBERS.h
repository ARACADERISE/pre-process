#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* Max sizes
    - sm: Signed Maxed
    - um: Unsigned Maxed
        - min ammount of um will always be zero
*/

// zero based value
#define ZERO_BASED       0U

// int2: signed: min/max
#define sm_int2_min     -2
#define sm_int2_max      2U
// unsigned: min/max
#define um_int2_min      0
#define um_int2_max      4U

// int4: signed: min/max
#define sm_int4_min     -4
#define sm_int4_max      4U
// unsigned: min/max
#define um_int4_min      0
#define um_int4_max      8U

// int6: signed: min/max
#define sm_int6_min     -62
#define sm_int6_max      61U
// unsigned: min/max
#define um_int6_min      0
#define um_int6_max      63U

// int 8: signed: min/max
#define sm_int8_min     -128
#define sm_int8_max      127U
// unsigned: min/max
#define um_int8_min      0
#define um_int8_max      255U

// int 16: signed: min/max
#define sm_int16_min    -32768
#define sm_int16_max     32767U
// unsigned: min/max
#define um_int16_min     0
#define um_int16_max     65535U

// int 20: signed: min/max
#define sm_int20_min    -524289
#define sm_int20_max     524287U
// unsigned: min/max
#define um_int20_min     0
#define um_int20_max     1048576U

// int 24: signed: min/max
#define sm_int24_min    -8388608
#define sm_int24_max     8388607U
// unsigned: min/max
#define um_int24_min     0
#define um_int24_max     16177215U

// int 28: signed: min/max
#define sm_int28_min   -134217729
#define sm_int28_max    134217728U
// unsigned: min/max
#define um_int28_min    0
#define um_int28_max    268435456U

// int 30: signed: min/max
#define sm_int30_min   -536870913
#define sm_int30_max    536870912U
// unsigned: min/max
#define um_int30_min    0
#define um_int30_max    1073741824U

// int 32: signed: min/max
#define sm_int32_min   -2147483648
#define sm_int32_max    2147483647U
// unsigned: min/max
#define um_int32_min    0
#define um_int32_max    4294967295U

// int 34: signed: min/max
#define sm_int40_min   -549755813889U
#define sm_int40_max    549755813887U
// unsigned: min/max
#define um_int40_min    0
#define um_int40_max    1099511627776U

// int 64: signed: min/max
#define sm_int64_min    -9223372036854775800U
#define sm_int64_max     9223372036854775800U
// unsigned: min/max
#define um_int64_min     0
#define um_int64_max     1844674407370955190 // Don't really know what would need this big of a number

/*
    typeof macro:
        - This macro checks the value of the number to each sm_int_min number, sm_int_max number
          and um_int_max number. If it matches any of them sm/um types, it copies the type to 
          returnType, prints the information to the screen, and the compilation of the macro
          ends.
        
        !NOTE: This macro can take in only one number of the max size of 64 bits
*/

// macro needed to assign the type and print the type
#define PRINT(assignTo,assignFrom,...) \
strcpy((*(assignTo)),assignFrom);\
fprintf(stdout,"TYPE: %s",assignFrom)
// macro needed to check if they are stricly the same
#define Strict(val,t) \
	if(\
		val==sm_int2_max||val==sm_int2_min||val==um_int2_max||\
		val==sm_int4_max||val==sm_int4_min||val==um_int4_max||\
		val==sm_int8_max||val==sm_int8_min||val==um_int8_max||\
		val==sm_int16_max||val==sm_int16_min||val==um_int16_max||\
		val==sm_int20_max||val==sm_int20_min||val==um_int20_max||val==sm_int24_max||val==sm_int24_min||\
		val==sm_int28_max||val==sm_int28_min||val==um_int28_max||\
		val==sm_int30_max||val==sm_int30_min||val==um_int30_max||\
		val==sm_int32_max||val==sm_int32_min||val==um_int32_max||\
		val==sm_int40_max||val==sm_int40_min||val==um_int40_max||\
		val==sm_int64_max||val==sm_int64_min||val==um_int64_max\
	) {\
		printf("Strictly exact");\
		strcpy((*(t)),"Strictly exact");\
	}

#define typeof(value,returnType) \
if(!(value>um_int64_max)){\
    if(!(value==ZERO_BASED)) {\
		Strict(value,returnType);\
		if(!(strcmp(*returnType,"Strictly exact")==0)){\
			if((value>=sm_int2_min&&!(value>sm_int2_max))||(!(value>um_int2_max))){\
				if(value<=um_int2_max&&value>-1){\
					PRINT(returnType,"um_int2_max");\
				}else{\
					PRINT(returnType,"sm_int2_min");\
				}\
			} else if((value>=sm_int4_min&&!(value>sm_int4_max))||(!(value>um_int4_max))) {\
				if(value<=um_int4_max&&value>-1){\
					PRINT(returnType,"um_int4_max");\
				} else{\
					PRINT(returnType,"sm_int4_min");\
				}\
			} else if((value>=sm_int6_min&&!(value>sm_int6_max))||!(value>um_int6_max)){\
				if(value<=um_int6_max&&value>-1){\
					PRINT(returnType,"um_int6_max");\
				} else{\
					PRINT(returnType,"sm_int6_min");\
				}\
			} else if((value>=sm_int8_min&&!(value>sm_int8_max))||!(value>um_int8_max)){\
				if(value<=um_int8_max&&value>-1){\
					PRINT(returnType,"um_int8_max");\
				} else {\
					PRINT(returnType,"sm_int8_min");\
				}\
			} else if((value>=sm_int16_min&&!(value>sm_int16_max))||!(value>um_int16_max)){\
				if(value<=um_int16_max&&value>-1){\
					PRINT(returnType,"um_int16_max");\
				} else {\
					PRINT(returnType,"sm_int16_min");\
				}\
			} else if((value>=sm_int20_min&&!(value>sm_int20_max))||!(value>um_int20_max)){\
				if(value<=um_int20_max&&value>-1){\
					PRINT(returnType,"um_int20_max");\
				} else {\
					PRINT(returnType,"sm_int20_min");\
				}\
			} else if((value>=sm_int24_min&&!(value>sm_int24_max))||!(value>um_int24_max)){\
				if(value<=um_int24_max&&value>-1){\
					PRINT(returnType,"um_int24_max");\
				} else {\
					PRINT(returnType,"sm_int24_min");\
				}\
			} else if((value>=sm_int28_min&&!(value>sm_int28_max))||!(value>um_int28_max)){\
				if(value<=um_int28_max&&value>-1){\
					PRINT(returnType,"um_int28_max");\
				} else {\
					PRINT(returnType,"sm_int28_min");\
				}\
			} else if((value>=sm_int30_min&&!(value>sm_int30_max))||!(value>um_int30_max)){\
				if(value<=um_int30_max&&value>-1){\
					PRINT(returnType,"um_int30_max");\
				} else {\
					PRINT(returnType,"sm_int30_min");\
				}\
			} else if((value>=sm_int32_min&&!(value>sm_int32_max))||!(value>um_int32_max)){\
				if(value<=um_int32_max&&value>-1){\
					PRINT(returnType,"um_int32_max");\
				} else{\
					PRINT(returnType,"sm_int32_min");\
				}\
			} else if((value>=sm_int40_min&&!(value>sm_int40_max))||!(value>um_int40_max)){\
				if(value<=um_int40_max&&value>-1){\
					PRINT(returnType,"um_int40_max");\
				} else {\
					PRINT(returnType,"sm_int40_min");\
				}\
			} else if((value>=sm_int64_min&&!(value>sm_int64_max))||!(value>um_int64_max)){\
				if(value<=um_int64_max&&value>-1){\
					PRINT(returnType,"um_int64_max");\
				} else {\
					PRINT(returnType,"sm_int64_min");\
				}\
			}\
		}\
	} else {\
		PRINT(returnType,"ZERO_BASED");\
	}\
} else {\
    fprintf(stderr,"\033[0;31mTOO LARGE OF A NUMBER");\
    strcpy((*(returnType)),"Too large of a number");\
    exit(EXIT_FAILURE);\
}
