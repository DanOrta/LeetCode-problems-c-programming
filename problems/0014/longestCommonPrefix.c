#include <string.h>
#include "longestCommonPrefix.h"

char* longestCommonPrefix(char** strs, int strsSize)
{
	if((strsSize <= 1))
		return strs[0];

	static char result[MAX_SIZE] = {0};
	int k = 0;

	(void)memset(result, 0, MAX_SIZE);

	for(int column = 0; column < MAX_SIZE; column++)
	{
        int outOfBoundaries = 0;

		for(int row = 1; row < strsSize; row++)
		{
			if(((int)strlen(strs[0]) == column) || ((int)strlen(strs[row]) == column))
			{
				outOfBoundaries = 1;
				break;
			}

			if(strs[0][column] != strs[row][column])
			{
				outOfBoundaries = 1;
				break;
			}
		}

		if(outOfBoundaries)
			break;

		result[k++] = strs[0][column];
	}

	return result;
}
