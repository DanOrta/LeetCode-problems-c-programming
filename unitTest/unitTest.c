#include <stdio.h>
#include <string.h>
#include "unitTest.h"

// PROBLEM #1
TEST(twoSum)
{
    expectedResult_twoSum inputValues[] =
    {
        {9, {2, 7, 11, 15}, 4, {0, 1}},
        {6, {3, 2, 4}, 3, {1, 2}},
        {6, {3, 3}, 2, {0, 1}},
        {100, {99, 8, -10, 1, 98}, 5, {0, 3}},
        {5, {2, 3, 7, 9}, 5, {0, 1}},
        {1, {1, -1, 2, 3, -2}, -1, {0, 2}},
        {20, {1, 2, 10, 20, 15}, 25, {3, 4}},
        {-5, {-1, -2, -3, -5, -7}, -9, {1, 2}}
    };
    const uint8_t numberOfTestCases = (uint8_t)(sizeof(inputValues) / sizeof(inputValues[0]));
    int tmpSize = 0;

    for(int i = 0; i < numberOfTestCases; i++)
    {
        ASSERT(memcmp(inputValues[i].output, twoSum(inputValues[i].nums, inputValues[i].numsLength, inputValues[i].target, &tmpSize), TWOSUM_OUT_SIZE) == PASSED, (i + 1));
    }
}

// PROBLEM #9
TEST(palindromeNumber)
{
    expectedResult_palindromeNumber inputTestCases[] =
    {
        {121, true},
        {-121, false},
        {10, false},
        {11, true},
        {123454321, true},
        {987656781, false},
        {2147483648, false},
        {2147447412, true}
    };
    const uint8_t numberOfTestCases = (uint8_t)(sizeof(inputTestCases) / sizeof(inputTestCases[0]));

    for(uint8_t i = 0u; i < numberOfTestCases; i++)
    {
        ASSERT(isPalindrome(inputTestCases[i].input) == inputTestCases[i].output, (i + 1));
    }
}

// PROBLEM #13
TEST(romanToInt)
{
    expectedResult_romanToInteger inputTestCases[] =
    {
        {"III", 3},
        {"LVIII", 58},
        {"LIV", 54},
        {"MMXXIX", 2029},
        {"DCCCXLV", 845},
        {"DXII", 512},
        {"MXXIV", 1024},
        {"MMMCMXCIX", 3999}
    };
    const uint8_t numberOfTestCases = (uint8_t)(sizeof(inputTestCases) / sizeof(inputTestCases[0]));

    for(uint8_t i = 0; i < numberOfTestCases; i++)
    {
        ASSERT(romanToInt(inputTestCases[i].s) == inputTestCases[i].output, (i + 1));
    }
}


// PROBLEM #14
TEST(longestCommonPrefix)
{
    expectedResult_longestCommonPrefix inputTest[] =
    {
        {"fl",   {"flower", "flow", "flight"}},
        {"flo",  {"float", "flood", "floyd"}},
        {"",     {"dog", "racecar", "airplane"}},
        {"",     {"a", "", ""}},
        {"pl",   {"plane", "plant", "pluto"}},
        {"",     {"", "", "a"}},
        {"",     {"", "", ""}},
        {"1234", {"1234", "1234d", "1234ñ"}}
    };
    const int numberOfTestCases = (int)(sizeof(inputTest) / sizeof(inputTest[0]));

    for(int i = 0; i < numberOfTestCases; i++)
        ASSERT(strcmp(inputTest[i].expected, longestCommonPrefix(inputTest[i].text, STRING_ARRAY_SIZE)) == PASSED, (i + 1));
}

// PROBLEM #20
TEST(validParenthesis)
{
    expectedResult_validParenthesis testCases[] =
    {
        {FALSE, ")[()])"},
        {TRUE, "[()]"},
        {FALSE, "[(])"},
        {FALSE, "{()["},
	{FALSE, "{[}"},
	{FALSE, "(]"},
        {TRUE, "((((((()))))))"},
        {TRUE, "{[]()[]()}"},
        {TRUE, ""},
        {FALSE, "("},
        {FALSE, ")"},
        {FALSE, "["},
        {FALSE, "]"},
        {FALSE, "{"},
        {FALSE, "(()"},
        {FALSE, "))("},
        {TRUE, "((()))"},
        {FALSE, "(([[[]]])"},
        {TRUE, "([])[]"},
        {FALSE, "[()]{"},
        {FALSE, "({[]}"},
        {TRUE, "{{[]}}"},
        {TRUE, "({[]})"},
        {TRUE, "()[]{}"},
        {TRUE, "(()(()))"},
        {FALSE, "(((("},
        {FALSE, ")))"},
        {TRUE, "([])[]({})"},
        {FALSE, "([)]"},
    };

    const int numberOfTestCases = (int)(sizeof(testCases) / sizeof(testCases[0]));

    for(int i = 0; i < numberOfTestCases; i++)
        ASSERT(testCases[i].expected == validParenthesis(testCases[i].text), (i + 1));
}

TEST(mySqrt)
{
    expectedResult_mySqrt inputTestCases[] =
    {
        {4, 2},
        {8, 2},
        {3, 1},
        {0, 0},
        {1, 1},
        {16, 4},
        {25, 5},
        {26, 5},
        {100, 10},
        {2147483647, 46340},
        {2147483648, 46340},
        {5, 2},
        {10000, 100}
    };
    const int numberOfTestCases = (int)(sizeof(inputTestCases) / sizeof(inputTestCases[0]));

    for(uint8_t i = 0; i < numberOfTestCases; i++)
    {
        ASSERT(mySqrt(inputTestCases[i].input) == inputTestCases[i].output, (i + 1));
    }
}
