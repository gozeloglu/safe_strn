/**
 * (C) Copyright - 12.03.2021
 * Author: Gökhan Özeloğlu - <gozeloglu@gmail.com>
 *
 * Test safe_strn library with different test scenarios
 *
 * Source code: https://github.com/gozeloglu/safe_strn
 * */

#include <assert.h>
#include "test_safe_str_lib.h"
#include <stdlib.h>
#include "../lib/safe_string.h"
#include "util.h"

void test_str_cpy() {
    char *src = "hello world";
    char *new_str = (char *) malloc(sizeof(char) * 12);
    int len = str_cpy(src, new_str, 11);

    assert__("str_cpy: string length is wrong", (len == 11))
    assert(new_str[11] == src[11]);
    printf("%s str_cpy: String copy successful.\n", CHECK_MARK);
}

void test_static_str_cpy() {
    char src[] = "hello world";
    char *new_str = (char *) malloc(sizeof(char) * 12);
    int len = str_cpy(src, new_str, 11);

    assert__("str_cpy: static string length is wrong", (len == 11))
    assert(new_str[11] == src[11]);
    printf("%s str_cpy: Static string copy successful.\n", CHECK_MARK);
}

void test_src_null_str_cpy() {
    char *src = NULL;
    char *new_str = (char *) malloc(sizeof(char) * 12);
    int len = str_cpy(src, new_str, 11);

    assert__("str_cpy: src not null", (len == -1))
    assert(len == -1);
    printf("%s str_cpy: src is null.\n", CHECK_MARK);
}

void test_str_null_new_str_cpy() {
    char *src = "hello world";
    char *new_str = NULL;
    int len = str_cpy(src, new_str, 11);

    assert__("str_cpy: new_str not null", (len == -2))
    assert(len == -2);
    printf("%s str_cpy: new_str is null.\n", CHECK_MARK);
}

void test_str_len() {
    char *chr = "this is a sample string.";
    size_t N = 24;

    int len = str_len(chr);

    assert__("str_len: Not equal length", (len == N))
    assert(len == N);
    printf("%s str_len: Equal length.\n", CHECK_MARK);
}

void test_static_str_len() {
    char chr[] = "this is a sample string.";
    size_t N = 24;

    int len = str_len(chr);

    assert__("str_len: Static string: not equal length", (len == N))
    assert(len == N);
    printf("%s str_len: Static string: Equal length.\n", CHECK_MARK);
}

void test_dynamic_str_len() {
    size_t N = 24;
    char *str = (char *) malloc(sizeof(char *) * (N + 1));
    char *src = "this is a sample string.";

    int i = 0;
    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }

    str[i] = '\0';

    int len = str_len(str);

    assert__("str_len: Dynamic string. Not equal length", (len == N))
    assert(len == N);
    printf("%s str_len: Dynamic string. Equal length of strings.\n", CHECK_MARK);
}

void test_null_string_length() {
    char *string = NULL;

    int len = str_len(string);
    int expected = -1;

    assert__("str_len: String not null", (len == expected))
    assert(len == expected);
    printf("%s str_len: String is null.\n", CHECK_MARK);
}

void test_str_cat() {
    int N = 10;

    char *src = (char *) malloc(sizeof(char *) * N + 1);
    char *append = "cd";

    src[0] = 'a';
    src[1] = 'b';
    src[2] = '\0';

    int len = str_cat(src, append, N, 2);

    assert__("str_cat: Both valid string. Not equal length", (len == 4))
    assert((len == 4));
    printf("%s str_cat: Both valid string.\n", CHECK_MARK);
}

void test_static_str_cat() {
    int N = 10;

    char *src = (char *) malloc(sizeof(char *) * N + 1);
    char append[] = "cd";

    src[0] = 'a';
    src[1] = 'b';
    src[2] = '\0';

    int len = str_cat(src, append, N, 2);

    assert__("str_cat: Static string. Both valid string. Not equal length", (len == 4))
    assert((len == 4));
    printf("%s str_cat: Static string. Both valid string.\n", CHECK_MARK);
}

void test_empty_src_str_cat() {
    int N = 10;

    char *src = (char *) malloc(sizeof(char *) * N + 1);
    char *append = "cd";

    int len = str_cat(src, append, N, 2);

    assert__("str_cat: Empty src string. Not equal length", (len == 2))
    assert((len == 2));
    printf("%s str_cat: Empty src string.\n", CHECK_MARK);
}

void test_empty_append_str_cat() {
    int N = 10;

    char *src = (char *) malloc(sizeof(char *) * N + 1);
    char *append;

    src[0] = 'a';
    src[1] = 'b';
    src[2] = '\0';

    int len = str_cat(src, append, N, 0);

    assert__("str_cat: Empty append string: Not equal length", (len == 2))
    assert((len == 2));
    printf("%s str_cat: Empty append string.\n", CHECK_MARK);
}

void test_str_cmp() {
    char *str1 = "abc";
    char *str2 = "abc";

    int res = str_cmp(str1, str2, 3, 3);

    assert__("str_cmp: Equal string: Not equal strings", (res == 0))
    assert((res == 0));
    printf("%s str_cmp: Equal strings\n", CHECK_MARK);
}

void test_static_str_cmp() {
    char str1[] = "abc";
    char str2[] = "abc";

    int res = str_cmp(str1, str2, 3, 3);

    assert__("str_cmp: Equal static strings: Not equal strings", (res == 0))
    assert((res == 0));
    printf("%s str_cmp: Equal static strings\n", CHECK_MARK);
}

void test_not_equal_str_cmp() {
    char *str1 = "abc";
    char *str2 = "abd";

    int res = str_cmp(str1, str2, 3, 3);

    assert__("str_cmp: Not equal string: str2 is before str1", (res == -1))
    assert((res == -1));
    printf("%s str_cmp: Not equal strings\n", CHECK_MARK);
}

void test_not_equal_str2_cmp() {
    char *str1 = "abd";
    char *str2 = "abc";

    int res = str_cmp(str1, str2, 3, 3);

    assert__("str_cmp: Not equal string: str1 is before str2", (res == 1))
    assert((res == 1));
    printf("%s str_cmp: Not equal strings\n", CHECK_MARK);
}

void test_empty_str_cmp() {
    char *str1 = "";
    char *str2 = "abc";

    int res = str_cmp(str1, str2, 0, 3);

    assert__("str_cmp: Empty string: str1 is empty", (res == -1))
    assert((res == -1));
    printf("%s str_cmp: Empty string\n", CHECK_MARK);
}

void test_null_str_cmp() {
    char *str1 = "abc";
    char *str2 = NULL;

    int res = str_cmp(str1, str2, 3, 0);

    assert__("str_cmp: Null string: str1 is empty", (res == 1))
    assert((res == 1));
    printf("%s str_cmp: Null string\n", CHECK_MARK);
}

void test_both_null_str_cmp() {
    char *str1 = NULL;
    char *str2 = NULL;

    int res = str_cmp(str1, str2, 0, 0);

    assert__("str_cmp: Both null strings: Both of them are not NULL", (res == 0))
    assert((res == 0));
    printf("%s str_cmp: Both of them null string\n", CHECK_MARK);
}

void test_str_mk() {
    char *s = str_mk("this is a sample string.", 100);

    int len = str_len(s);
    int isSame = str_cmp("this is a sample string.", s, 24, 24);

    assert__("str_mk: String length is wrong.", (len == 24))
    assert((len == 24));

    assert__("str_mk: String is not the same.", (isSame == 0))
    assert(isSame == 0);

    printf("%s str_mk: String and its length correct.\n", CHECK_MARK);
}

void test_empty_str_mk() {
    char *s = str_mk("", 100);

    int len = str_len(s);
    int isSame = str_cmp("", s, 20, 0);

    assert__("str_mk: Empty string length is wrong.", (len == 0))
    assert((len == 0));

    assert__("str_mk: Empty string is not the same.", (isSame == 0))
    assert(isSame == 0);

    printf("%s str_mk: Empty string and its length correct.\n", CHECK_MARK);
}

void test_less_mem_str_mk() {
    char *s = str_mk("this is a sample string.", 10);

    int len = str_len(s);
    int isSame = str_cmp("this is a ", s, 24, len);

    assert__("str_mk: Less length string length is wrong.", (len == 10))
    assert((len == 10));

    assert__("str_mk: String is not the same.", (isSame == 0))
    assert(isSame == 0);

    printf("%s str_mk: Less length string and its length correct.\n", CHECK_MARK);
}
