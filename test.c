#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "lucie_lib.h"

#define run_test(x) run_test_f(#x, x())
#define mkbool(x) ((x) ? 1 : 0)
#define mzero(x) memset(x, 0, sizeof(x))

int run_test_f(const char* name, int result) {
	printf("TEST %s = %s\n", name, result ? "OK" : "FAIL");
	return result;
}

int test_l_str_dup() {
	int test_ok;
	const char *s; 
	char *ret;
	s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	ret = l_str_dup(s);
	test_ok = (strcmp(ret, s) == 0);
	free(ret);
	return test_ok;
}

int test_l_str_catx() {
	char buff[64], *buff_p, *ret;
	const char* expected;
	int test_ok = 0;
	buff_p = buff;
	mzero(buff);
	expected = "Lorem ipsum dolor sit amet.";
	ret = l_str_catx(buff_p, "Lorem ", "ipsum ", "dolor ", "sit ", "amet.", NULL);
	/* Function must return a pointer to str, and also have the string concated as excepted. */
	test_ok = mkbool(ret == buff_p && strcmp(buff_p, expected) == 0);
	if (!test_ok) { return test_ok; }
	memset(buff, 0, sizeof(buff));
	strcpy(buff, "Lorem ipsum ");
	ret = l_str_catx(buff_p, "dolor ", "sit ", "amet.", NULL);
	test_ok = mkbool(ret == buff_p && strcmp(buff_p, expected) == 0);
	return test_ok;
}

int test_l_int_base_to_str() {
	char buff[64], *buff_p, *ret;
	const char *expected;
	int num, test_ok;
	mzero(buff);
	expected = "142554060";
	num = 142554060;
	buff_p = buff;
	ret = l_int_base_to_str(num, 10, NULL, buff_p);
	test_ok = mkbool(ret == buff_p && strcmp(buff_p, expected) == 0);
	if (!test_ok) { return test_ok; }
	mzero(buff);
	ret = l_int_base_to_str(num, 10, NULL, NULL);
	test_ok = (strcmp(ret, expected) == 0);
	free(ret);
	return test_ok;
}

int test_l_str_to_int_base() {
	return mkbool(l_str_to_int_base("142554060", 10, NULL) == 142554060);
}

int test_l_str_slice() {
	/*@TODO: Implement this */
	return 1;
}

int main(int argc, char **argv) {
	if ( sizeof(argc) || sizeof(argv) ) /* Only putting this to avoid Compiler Warning */
	return (run_test(test_l_str_dup) &&
			run_test(test_l_str_catx) &&
			run_test(test_l_int_base_to_str) &&
			run_test(test_l_str_to_int_base) &&
			run_test(test_l_str_slice)	) ? 0 : 1;
}
