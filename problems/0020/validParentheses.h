#ifndef VALIDPARENTHESIS_H
#define VALIDPARENTHESIS_H

#include "types.h"

#define ROUND_OP	0x28	// '('
#define ROUND_CP	0x29	// ')'
#define SQUARE_OP	0x5B	// '['
#define SQUARE_CP	0x5D	// ']'
#define CURLY_OP	0x7B	// '{'
#define CURLY_CP	0x7D	// '}'

#define validParenthesis isValid
#define isEven(x) ((x % 2 == 0) ? TRUE : FALSE)

typedef struct
{
	int top;
	char* stack;
} Stack;

// Original function signature
extern bool isValid(char*);

// Auxiliary functions


#endif
