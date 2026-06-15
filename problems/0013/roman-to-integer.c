#include <stdlib.h>
#include "roman-to-integer.h"

int romanToInt(char * s)
{
    char* pt = s;
    int sum = 0;

    for(int counter = 0;(*pt); pt++, counter++)
    {
        sum += (*pt) == 'M' ? 1000 : (*pt) == 'D' ? 500 : (*pt) == 'C' ? 100 : (*pt) == 'L' ? 50 : 
               (*pt) == 'X' ? 10 : (*pt) == 'V' ? 5 : (*pt) == 'I' ? 1 : 0;

        if(((pt - 1) != NULL) && (counter != 0))
        {
            switch(*(pt - 1))
            {
                case 'I':
                    if((*pt == 'V') || (*pt == 'X'))
                        sum -= 2;
                    break;
                case 'X':
                    if((*pt == 'L') || (*pt == 'C'))
                        sum -= 20;
                    break;
                case 'C':
                    if((*pt == 'D') || (*pt == 'M'))
                        sum -= 200;
                    break;
                default:
                    sum += 0;
            }
        }
    }

    return sum;
}
