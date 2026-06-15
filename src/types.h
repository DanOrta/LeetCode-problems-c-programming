#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

#ifndef TRUE
#	define TRUE 1
#endif
#ifndef FALSE
#	define FALSE 0
#endif

#ifndef NULL
#	define NULL ((void*)0)
#endif

#define UNUSED __attribute__((unused))

typedef unsigned char   uint8_t;
typedef signed int      sint32_t;
typedef unsigned int    uint32_t;

#endif
