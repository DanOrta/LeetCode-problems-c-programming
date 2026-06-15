#include <stdlib.h>
#include <math.h>
#include "types.h"
#include "palindrome-number.h"

bool isPalindrome(int x)
{
    if(x < 0) return false;
    if(x == 0) return true;

    int numOfDigits = log10(x) + 1;
    uint8_t * arrayOfDigits = (uint8_t*)calloc(numOfDigits, sizeof(uint8_t));

    while(x)
    {
        *arrayOfDigits = x % 10;
        arrayOfDigits++;
        x /= 10;
    }

    arrayOfDigits -= numOfDigits;

    for(int i = 0; i < (numOfDigits / 2); i++)
        if(arrayOfDigits[i] != arrayOfDigits[(numOfDigits - 1) - i]) return false;

    free(arrayOfDigits);
    return true;
}
