/**
 * JoshAssert, by Josh Max
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <http://unlicense.org/>
 */

#ifndef JOSHASSERT_H
#define JOSHASSERT_H

#ifndef __cplusplus
# error "This only works for c++"
#endif

#include <vector>
#include <iostream>
#include <string>

struct test_result {
    const char *assertation;
    const char *file;
    const unsigned int line;
    const char *func;
    const bool is_success;
};

static std::vector<test_result> tests;

void __jassert (const char *__assertion, const char *__file,
                           unsigned int __line, const char *__function,
                           bool __is_success)
{
    test_result res {__assertion, __file, __line, __function, __is_success};
    tests.push_back(res);
}

void __jassert_okay (const char *__assertion, const char *__file,
                           unsigned int __line, const char *__function)
{
    __jassert (__assertion, __file, __line, __function, true);
}

void __jassert_fail (const char *__assertion, const char *__file,
                           unsigned int __line, const char *__function)
{
    __jassert (__assertion, __file, __line, __function, false);;
}

void jassert_print(void)
{
    unsigned int passes = 0;
    unsigned int failures = 0;

    std::cout << std::string(40, '=') << std::endl;
    for (int print_passes = 1; print_passes % 3; print_passes++)
    {
        for (int i = 0; i < tests.size(); i++)
        {
            bool is_pass = static_cast<bool>(print_passes % 2);
            if (is_pass == tests[i].is_success)
            {
                is_pass ? passes++ : failures++;
                std::cout << tests[i].assertation
                    << " in file "
                    << tests[i].file
                    << " at line "
                    << tests[i].line
                    << " " << (is_pass ? "Passed" : "FAILED")
                    << std::endl;
            }
        }
    }

    std::cout << std::endl << passes
        << " passes and "
        << failures
        << " failures of a total of "
        << passes + failures
        << " test cases."
        << std::endl;
}

#define __ASSERT_FUNCTION       __extension__ __PRETTY_FUNCTION__

#define JOSH_ASSERT(expr)                                               \
     (static_cast <bool> (expr)                                         \
      ? __jassert_okay (#expr, __FILE__, __LINE__, __ASSERT_FUNCTION)   \
      : __jassert_fail (#expr, __FILE__, __LINE__, __ASSERT_FUNCTION))

#define TEST_RESULTS jassert_print

// Basic CATCH compatibility
#define CHECK JOSH_ASSERT

#define REQUIRE(expr)                   \
     CHECK(expr);                       \
     if (!static_cast<bool>(expr))      \
     {                                  \
         return;                        \
     }                                  \

#define TEST_CASE(...)          \
     void __runtests(void);     \
     int main(void)             \
     {                          \
         __runtests();          \
         TEST_RESULTS();        \
         return 0;              \
     }                          \
     void __runtests(void)

#endif // JOSHASSERT_H
