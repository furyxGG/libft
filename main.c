#include "libft.h"

#include <stdio.h>  // printf
#include <stdlib.h> // malloc, free, exit
#include <string.h> // strcmp, strlen

void run_test(const char *test_name, const char *s, unsigned int start, size_t len, const char *expected)
{
    char *result = ft_substr(s, start, len);

    printf("--- Test Case: %s ---\n", test_name);
    printf("Original string: \"%s\"\n", s ? s : "(NULL)");
    printf("Start index: %u\n", start);
    printf("Max length: %zu\n", len);

    if (expected == NULL) // Expecting NULL return (e.g., for s == NULL or malloc failure)
    {
        if (result == NULL)
        {
            printf("Result: (NULL) - PASSED (Expected NULL)\n");
        }
        else
        {
            printf("Result: \"%s\" - FAILED (Expected NULL, got \"%s\")\n", result, result);
            free(result); // Free if not NULL
        }
    }
    else // Expecting a specific string
    {
        if (result == NULL)
        {
            printf("Result: (NULL) - FAILED (Expected \"%s\", got NULL)\n", expected);
        }
        else
        {
            if (strcmp(result, expected) == 0)
            {
                printf("Result: \"%s\" - PASSED\n", result);
            }
            else
            {
                printf("Result: \"%s\" - FAILED (Expected \"%s\")\n", result, expected);
            }
            free(result); // Free the allocated memory
        }
    }
    printf("\n");
}

int main()
{
    // --- Normal Cases ---
    run_test("Normal Case 1 (Middle)", "Hello World", 6, 5, "World");
    run_test("Normal Case 2 (Beginning)", "Hello World", 0, 5, "Hello");
    run_test("Normal Case 3 (End)", "Hello World", 6, 100, "World"); // len > remaining
    run_test("Normal Case 4 (Full String)", "Hello World", 0, 11, "Hello World");
    run_test("Normal Case 5 (Single Char)", "Hello", 2, 1, "l");

    // --- Edge Cases for 'start' ---
    run_test("Edge Case 1 (start at end)", "Hello", 5, 5, ""); // Should return an empty string
    run_test("Edge Case 2 (start beyond end)", "Hello", 10, 5, ""); // Should return an empty string

    // --- Edge Cases for 'len' ---
    run_test("Edge Case 3 (len is 0)", "Hello World", 0, 0, "");
    run_test("Edge Case 4 (len is 0, start in middle)", "Hello World", 6, 0, "");
    run_test("Edge Case 5 (len is very large)", "Short", 0, 1000, "Short");

    // --- Edge Cases for 's' ---
    run_test("Edge Case 6 (Empty string s)", "", 0, 5, "");
    run_test("Edge Case 7 (Empty string s, start beyond)", "", 10, 5, "");

    // --- NULL String Case (ft_substr should handle this gracefully, returning NULL) ---
    // This assumes ft_substr returns NULL if s is NULL.
    // If your ft_substr crashes on NULL input, this test will fail.
    run_test("Edge Case 8 (NULL string s)", NULL, 0, 5, NULL);

    // --- Combined Edge Cases ---
    run_test("Combined Case 1 (start at end, len 0)", "Test", 4, 0, "");
    run_test("Combined Case 2 (start beyond end, len 0)", "Test", 10, 0, "");
    run_test("Combined Case 3 (start in middle, len too long)", "Programming", 3, 20, "gramming");

    printf("\nAll test cases completed.\n");

    return 0;
}
