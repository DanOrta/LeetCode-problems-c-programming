#ifndef UNITTEST_H
#define UNITTEST_H

#include "types.h"
// Include the header files of the APIs (exercises)
#include "0001/two-sum.h"
#include "0009/palindrome-number.h"
#include "0013/roman-to-integer.h"
#include "0014/longestCommonPrefix.h"
#include "0020/validParentheses.h"
#include "0069/sqrt.h"

#define STRING_ARRAY_SIZE    3
#define PASSED     0
#define FAILED     1

// COLORS
#define CYAN    "\033[01;36m"
#define GREEN   "\033[01;32m"
#define RED     "\033[01;31m"
#define RESET   "\033[00m"
#define YELLOW  "\033[01;33m"

// Custom types for the test cases. DO NOT USE THEM SOME WHERE ELSE.

typedef struct // TYPEDEF FOR PROBLEM #1
{
    sint32_t target;
    sint32_t nums[TARGET_MAX_SIZE]; // Couldn't find a more "elegant" solution
    uint8_t  numsLength;
    sint32_t output[TWOSUM_OUT_SIZE];
} expectedResult_twoSum;

typedef struct // TYPEDEF FOR PROBLEM #9
{
   sint32_t input;
   bool output;
} expectedResult_palindromeNumber;

typedef struct // TYPEDEF FOR PROBLEM #13
{
    char* s;
    int output;
} expectedResult_romanToInteger;

typedef struct // TYPEDEF FOR PROBLEM #14
{
    char* expected;
    char* text[STRING_ARRAY_SIZE];
} expectedResult_longestCommonPrefix;

typedef struct // Typedef for problem #22
{
    bool expected;
    char* text;
} expectedResult_validParenthesis;

typedef struct // Typedef for problem #69
{
    uint32_t input;
    uint32_t output;
} expectedResult_mySqrt;

// ASSERT Macros
#define ASSERT_FAILED(i)    (void)fprintf(stderr, "Test case #%d %sFAILED%s.\n", i, RED, RESET)
#define ASSERT_PASSED(i)    (void)fprintf(stdout, "Test case #%d %sPASSED%s.\n", i, GREEN, RESET)
#define ASSERT(expr, i)     if(expr) {              \
                                ASSERT_PASSED(i);   \
                            } else {                \
                                ASSERT_FAILED(i);   \
                             }

#define TEST(name)      void name##_unitTest(void)
#define RUN(name)       (void)printf("\n%sExecuting: %s%s%s.\n", CYAN, YELLOW, #name, RESET); \
                        name##_unitTest()

// Function prototypes
extern TEST(twoSum);
extern TEST(palindromeNumber);
extern TEST(romanToInt);
extern TEST(longestCommonPrefix);
extern TEST(validParenthesis);
extern TEST(mySqrt);

#endif
