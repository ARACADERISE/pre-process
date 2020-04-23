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
#define sm_int2_max      3
// unsigned: min/max
#define um_int2_min      0
#define um_int2_max      5U

// int4: signed: min/max
#define sm_int4_min     -5
#define sm_int4_max      20
// unsigned: min/max
#define um_int4_min      0
#define um_int4_max      25U

// int6: signed: min/max
#define sm_int6_min     -62
#define sm_int6_max      61
// unsigned: min/max
#define um_int6_min      0
#define um_int6_max      63U

// int 8: signed: min/max
#define sm_int8_min     -128
#define sm_int8_max      127
// unsigned: min/max
#define um_int8_min      0
#define um_int8_max      255U

// int 16: signed: min/max
#define sm_int16_min    -32768
#define sm_int16_max     32767
// unsigned: min/max
#define um_int16_min     0
#define um_int16_max     65535U

// int 20: signed: min/max
#define sm_int20_min    -524289
#define sm_int20_max     524287
// unsigned: min/max
#define um_int20_min     0
#define um_int20_max     1048576U

// int 24: signed: min/max
#define sm_int24_min    -8388608
#define sm_int24_max     8388607
// unsigned: min/max
#define um_int24_min     0
#define um_int24_max     16177215U

// int 28: signed: min/max
#define sm_int28_min   -134217729
#define sm_int28_max    134217728
// unsigned: min/max
#define um_int28_min    0
#define um_int28_max    268435456U

// int 30: signed: min/max
#define sm_int30_min   -536870913
#define sm_int30_max    536870912
// unsigned: min/max
#define um_int30_min    0
#define um_int30_max    1073741824U

// int 32: signed: min/max
#define sm_int32_min   -2147483648
#define sm_int32_max    2147483647
// unsigned: min/max
#define um_int32_min    0
#define um_int32_max    4294967295U

// int 34: signed: min/max
#define sm_int40_min   -549755813889
#define sm_int40_max    549755813887
// unsigned: min/max
#define um_int40_min    0
#define um_int40_max    1099511627776U

// int 64: signed: min/max
#define sm_int64_min    -9223372036854775807
#define sm_int64_max     9223372036854775806
// unsigned: min/max
#define um_int64_min     0
#define um_int64_max     18446744073709551614U // Don't really know what would need this big of a number

/*
    typeof macro:
        - This macro checks the value of the number to each sm_int_min number, sm_int_max number
          and um_int_max number. If it matches any of them sm/um types, it copies the type to 
          returnType, prints the information to the screen, and the compilation of the macro
          ends.
		- This macro works better when working with:
			- long int
			- long long int
			- long signed int
			- long long signed int
			- long unsigned int
			- long long unsigned int
        
        !NOTE: This macro can take in only one number of the max size of 64 bits

		TO-DO: major reputition...could fix it later?
*/

// macro needed to assign the type and print the type
#define PRINT(assignTo,assignFrom,...) \
strcpy((*(assignTo)),assignFrom);\
fprintf(stdout,"TYPE: %s\n",assignFrom)

// This macro is used in the macro Strict
#define PRINT_STRICT(assignTo,toPrint) \
strcpy((*(assignTo)),"Strictly exact");\
fprintf(stdout,"Stricty related to: %s\n",toPrint)
// macro needed to check if they are stricly the same as the um_int_max value
#define StrictUmMax(val,t) \
	if(val==um_int2_max) {PRINT_STRICT(t,"um_int2_max");}else if(val==um_int4_max) {PRINT_STRICT(t,"um_int4_max");}\
	else if(val==um_int6_max) {PRINT_STRICT(t,"um_int6_max");}else if(val==um_int8_max) {PRINT_STRICT(t,"um_int8_max");}\
	else if(val==um_int16_max) {PRINT_STRICT(t,"um_int16_max");}else if(val==um_int20_max) {PRINT_STRICT(t,"um_int16_max");}\
	else if(val==um_int24_max) {PRINT_STRICT(t,"um_int24_max");}else if(val==um_int28_max) {PRINT_STRICT(t,"um_int28_max");}\
	else if(val==um_int30_max) {PRINT_STRICT(t,"um_int30_max");}else if(val==um_int32_max) {PRINT_STRICT(t,"um_int32_max");}\
	else if(val==um_int40_max) {PRINT_STRICT(t,"um_int40_max");}else if(val==um_int64_max) {PRINT_STRICT(t,"um_int64_max");}

// TO-DO: Finish this function. Should look exactly like the StrictUmMax macro
#define StrictSmMax(val,t) \
	if(val==sm_int64_max) {PRINT_STRICT(t,"sm_int64_max");}

#define typeof(value,returnType) \
if(!(value==ZERO_BASED)) {\
	/* Checking if the values are strictly related to defined numbers */\
	StrictUmMax(value,returnType);\
	StrictSmMax(value,returnType);\
	if((value>=sm_int2_min&&!(value>um_int2_max))||!(value>=sm_int4_min||value<=sm_int4_max)){\
		if(value<=um_int2_max&&value>-1){\
				PRINT(returnType,"um_int2_max");\
			} else {\
				PRINT(returnType,"sm_int2_min");\
			}\
	}else if((value>=sm_int4_min&&!(value>um_int4_max))&&(value<sm_int6_max&&value>sm_int6_min)) {\
		if(value<=um_int4_max&&value>-1) {\
			if(value>sm_int4_max) {\
				PRINT(returnType,"um_int4_max");\
			} else {\
				PRINT(returnType,"sm_int4_max");\
				}\
		} else {\
			PRINT(returnType,"sm_int4_min");\
		}\
	}else if((value>=sm_int6_min&&!(value>um_int6_max))&&(value<sm_int8_max||value>sm_int8_min)){\
		if(value<=um_int6_max&&value>-1) {\
			if(value>sm_int6_max) {\
				PRINT(returnType,"um_int6_max");\
			} else {\
				PRINT(returnType,"sm_int6_max");\
			}\
		} else {\
			PRINT(returnType,"sm_int8_min");\
		}\
	}else if((value>=sm_int8_min&&!(value>um_int8_max))&&(value<sm_int16_max||value>sm_int16_min)){\
		if(value<=um_int8_max&&value>-1) {\
			if(value>sm_int8_max) {\
				PRINT(returnType,"um_int8_max");\
			} else {\
				PRINT(returnType,"sm_int8_max");\
			}\
		} else {\
			PRINT(returnType,"sm_int8_min");\
		}\
	}else if((value>=sm_int16_min&&!(value>um_int16_max))&&(value<sm_int20_max&&value>sm_int20_min)){\
		if(value<=um_int16_max&&value>-1) {\
			if(value>sm_int16_max) {\
				PRINT(returnType,"um_int16_max");\
			} else {\
				PRINT(returnType,"sm_int16_max");\
			}\
		} else {\
			PRINT(returnType,"sm_int16_min");\
		}\
	}else if((value>=sm_int20_min&&!(value>um_int20_max))&&(value<sm_int24_max&&value>sm_int24_min)) {\
		if(value<=um_int24_max&&value>-1) {\
			if(value>sm_int24_max) {\
				PRINT(returnType,"um_int24_max");\
			} else {\
				PRINT(returnType,"sm_int24_max");\
			}\
		} else {\
			PRINT(returnType,"sm_int24_min");\
		}\
	}else if((value>=sm_int24_min&&!(value>um_int24_max))&&(value<sm_int28_max&&value>sm_int28_min)){\
		if(value<=um_int24_max&&value>-1) {\
			if(value>sm_int24_max) {\
				PRINT(returnType,"um_int24_max");\
			} else {\
				PRINT(returnType,"sm_int24_max");\
			}\
		} else {\
			PRINT(returnType,"sm_int24_min");\
		}\
	}else if((value>=sm_int28_min&&!(value>um_int28_max))&&(value<sm_int30_max&&value>sm_int30_min)){\
		if(value<=um_int28_max&&value>-1) {\
			if(value>sm_int28_max) {\
				PRINT(returnType,"um_int28_max");\
			} else {\
				PRINT(returnType,"sm_int28_max");\
			}\
		} else {\
			PRINT(returnType,"sm_int28_min");\
		}\
	}else if((value>=sm_int30_min&&!(value>um_int30_max))&&(value<sm_int32_max&&value>sm_int32_min)){\
		if(value<=um_int30_max&&value>-1) {\
			if(value>sm_int40_max) {\
				PRINT(returnType,"um_int40_max");\
			} else {\
				PRINT(returnType,"sm_int40_max");\
			}\
		} else {\
			PRINT(returnType,"sm_int40_min");\
		}\
	}else if((value>=sm_int32_min&&!(value>um_int32_max))&&(value<sm_int40_max&&value>sm_int40_min)){\
		if(value<=um_int32_max&&value>-1) {\
			if(value>sm_int32_max) {\
				PRINT(returnType,"um_int32_max");\
			} else {\
				PRINT(returnType,"sm_int32_max");\
			}\
		} else {\
			PRINT(returnType,"sm_int32_min");\
		}\
	} else if((value>=sm_int40_min&&!(value>um_int40_max))&&(value<sm_int64_max&&value>sm_int64_min)) {\
		if(value<=um_int40_max&&value>-1) {\
			if(value>sm_int40_max) {\
				PRINT(returnType,"um_int40_max");\
			} else {\
				PRINT(returnType,"sm_int40_max");\
			}\
		} else {\
			PRINT(returnType,"sm_int40_min");\
		}\
 	} else if((value>=sm_int64_min&&!(value>um_int64_max))){\
		if(value<=um_int64_max&&value>-1) {\
			if(value>sm_int64_max) {\
				PRINT(returnType,"um_int64_max");\
			} else {\
				PRINT(returnType,"sm_int64_max");\
			}\
		} else {\
			PRINT(returnType,"sm_int64_min");\
		}\
	}\
} else {\
	PRINT(returnType,"ZERO_BASED");\
}
