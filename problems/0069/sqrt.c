#include "types.h"
#include "sqrt.h"

// Max value is: 2,147,483,647. Which means that its square root is
// 46,340.95 -> (int)(46,340.95) = 46,340
uint32_t mySqrt(int x)
{
    // Precalculated values!
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(x >= 0x7FFEA810) return 46340;
    if(x >= 0x7FFD3E09) return 46339;

    uint32_t top2N = 0U;

    for(int i = 0; i < (int)(sizeof(int) * 8); i++)
    {
        top2N = (1U << i);
        if(top2N >= ((uint32_t)x))
        {
            top2N >>= (i / 2);
            top2N |= (top2N >> 1);
            top2N /= 2;
            break;
        }
    }

    if((top2N * top2N) == (uint32_t)x) return top2N;

    if((top2N * top2N) > (uint32_t)x)
    {
        // Decremental loop
        for(;; top2N--)
            if((top2N * top2N) <= (uint32_t)x) return top2N;
    }
    else
    {
        // Incremental loop
        for(;; top2N++)
        {
            if((top2N * top2N) == (uint32_t)x) return top2N;
            if((top2N * top2N) > (uint32_t)x) return (top2N - 1);
        }
    }

    return top2N;
}
