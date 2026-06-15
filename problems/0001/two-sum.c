#include <stdlib.h>
#include "two-sum.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//  TODO: Add the function prototype
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int * solution = (int*)malloc(sizeof(int) * 2);
    
    for(int i = 0; i < (numsSize - 1); i++)
    {
        for(int j = (i + 1); j < numsSize; j++)
        {
            if(target == (nums[i] + nums[j])) // we found it!
            {
                solution[0] = i;
                solution[1] = j;
                *returnSize = 2;
                return solution;
            }
        }
    }
    
    *returnSize = 1;
    return NULL;
}
