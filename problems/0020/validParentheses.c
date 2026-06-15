#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "validParentheses.h"

Stack stack;

bool isValid(UNUSED char* s)
{
    int len = (int)strlen(s);
    char stack[len];
    int top = -1;

    for(int i = 0; i < len; i++)
    {
        if((ROUND_OP == s[i]) || (CURLY_OP == s[i]) || (SQUARE_OP == s[i]))
        {
            stack[++top] = s[i];
        }
        else
        {
            if((-1 == top) ||
            ((ROUND_CP == s[i]) && (ROUND_OP != stack[top])) ||
            ((CURLY_CP == s[i]) && (CURLY_OP != stack[top])) ||
            ((SQUARE_CP == s[i]) && (SQUARE_OP != stack[top])))
            {
                return false;
            }

            top--;
        }
    }

    return top == -1; 
}
