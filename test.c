#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ensure NDEBUG if DEBUG is not present
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#endif
#include <assert.h>

#include "liblucie.h"

#define run_test(x) run_test_f(#x, x())
#define mkbool(x) ((x) ? 1 : 0)
#define mzero(x) memset(x, 0, sizeof(x))
#define free_if(x)                                                                                           \
    if (x) { free(x); }

int run_test_f(const char *name, int result) {
    printf("TEST %s = %s\n", name, result ? "OK" : "FAIL");
    return result;
}

int test_l_str_dup() {
    const char *e = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    char *ret = l_str_dup(e);
    int test_ok = (strcmp(ret, e) == 0);
    free_if(ret);
    return test_ok;
}

int test_l_str_catx() {
    char buff[64] = {0};
    const char *expected = "Lorem ipsum dolor sit amet.";
    int test_ok = 0;
    char *buff_p = buff;
    mzero(buff);
    const char *ret = l_str_catx(buff_p, "Lorem ", "ipsum ", "dolor ", "sit ", "amet.", NULL);
    /* Function must return a pointer to str, and also have the string concated
     * as expected. */
    test_ok = mkbool(ret == buff_p && strcmp(buff_p, expected) == 0);
    if (!test_ok) { return test_ok; }
    mzero(buff);
    strcpy(buff, "Lorem ipsum ");
    ret = l_str_catx(buff_p, "dolor ", "sit ", "amet.", NULL);
    test_ok = mkbool(ret == buff_p && strcmp(buff_p, expected) == 0);
    return test_ok;
}

int test_l_int_base_to_str() {
    char buff[64] = {0};
    const char *expected;
    expected = "142554060";
    int num = 142554060;
    char *buff_p = buff;
    char *ret = l_int_base_to_str(num, 10, NULL, buff_p);
    int test_ok = mkbool(ret == buff_p && strcmp(buff_p, expected) == 0);
    if (!test_ok) { return test_ok; }
    mzero(buff);
    ret = l_int_base_to_str(num, 10, NULL, NULL);
    test_ok = mkbool(strcmp(ret, expected) == 0);
    free_if(ret);
    return test_ok;
}

int test_l_str_to_int_base() { return mkbool(l_str_to_int_base("142554060", 10, NULL) == 142554060); }

int test_l_str_slice() {
    char str[64] = {0}, out[64] = {0};
    int found = 0;
    size_t slice_len;
    strcpy(str, "Greetings,,From,This,Code");
    char *slice = &str[0];
    char *out_p = &out[0];
    do {
        found = l_str_slice(slice, ',', &slice_len);
        strncat(out_p, slice, slice_len);
        strcat(out_p, ";");
        slice = slice + slice_len + 1;
    } while (found);
    return mkbool(strcmp(out_p, "Greetings;;From;This;Code;") == 0);
}

int test_l_str_is_surrc() {
    char str[64] = {0};
    char *str_p = &str[0];
    strcpy(str, "\"Hello World\"");
    int test_ok = l_str_is_surrc(str_p, '\"');

    if (!test_ok) { return test_ok; }

    mzero(str);
    strcpy(str, "Hello World");
    test_ok = mkbool(l_str_is_surrc(str_p, '\"') == 0);

    return test_ok;
}

int test_l_str_rm_surrc() {
    char str[64] = {0};
    char *str_p = &str[0];
    strcpy(str, "\"Hello World\"");
    return mkbool(strcmp(l_str_rm_surrc(str_p, '\"'), "Hello World") == 0);
}

int test_l_strn_trim_left() {
    const char *expected = "Test";
    char str[16] = {0};
    strcpy(str, "  \tTest");
    assert(str);
    char *res = l_strn_trim_left(&str[0], strlen(&str[0]));
    assert(res);
    return mkbool(strcmp(res, expected) == 0);
}

int test_l_strn_trim_left_ro() {
    const char *expected = "Test";
    char str[16] = {0};
    strcpy(str, "  \tTest");
    size_t offset = l_strn_trim_left_ro(&str[0], strlen(&str[0]));
    return mkbool(strcmp(&str[0] + offset, expected) == 0);
}

int test_l_strn_trim_right() {
    const char *expected = "Test";
    char str[16] = {0};
    strcpy(str, "Test\t   ");
    assert(str);
    char *res = l_strn_trim_right(&str[0], strlen(&str[0]));
    assert(res);
    return mkbool(strcmp(res, expected) == 0);
}

int test_l_strn_trim_right_ro() {
    const char *expected = "Test";
    char str[32] = {0};
    strcpy(str, "Test\t  ");
    size_t len = l_strn_trim_right_ro(&str[0], strlen(&str[0]));
    return mkbool(memcmp(&str[0], expected, len) == 0);
}

int test_l_strn_starts_with() {
    const char *h1 = "Needle Haystack";
    const char *n1 = "Needle";
    int test_ok = mkbool(l_strn_starts_with(h1, n1, strlen(h1), strlen(n1)));

    if (!test_ok) { return 0; }

    const char *n2 = "Unrelated";
    test_ok = mkbool(!l_strn_starts_with(h1, n2, strlen(h1), strlen(n2)));

    return test_ok;
}

int test_l_strn_char_cnt() {
    // @TODO
    // size_t l_strn_char_cnt(const char *str, size_t str_len, const char c);
    fprintf(stderr, "Warning: test_l_strn_char_cnt not yet implemented.\n");
    return 1;
}

int main(int argc, char **argv) {
    if (sizeof(argc) || sizeof(argv)) // Only putting this to avoid Compiler Warning
        return (run_test(test_l_str_dup) && run_test(test_l_str_catx) && run_test(test_l_int_base_to_str) &&
                run_test(test_l_str_to_int_base) && run_test(test_l_str_slice) &&
                run_test(test_l_str_is_surrc) && run_test(test_l_str_rm_surrc)) &&
                       run_test(test_l_strn_trim_left) && run_test(test_l_strn_trim_left_ro) &&
                       run_test(test_l_strn_trim_right_ro) && run_test(test_l_strn_starts_with) &&
                       run_test(test_l_strn_char_cnt)
                   ? 0
                   : 1;
}
