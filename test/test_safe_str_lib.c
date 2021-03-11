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

    assert__("wrong len", (len == 11));
    assert(new_str[11] == src[11]);
    printf("%s Passed test.\n", CHECK_MARK);
}

void test_src_null_str_cpy() {
    char *src = NULL;
    char *new_str = (char *) malloc(sizeof(char) * 12);
    int len = str_cpy(src, new_str, 11);

    assert__("src not null", (len == -1));
    assert(len == -1);
    printf("%s Passed test.\n", CHECK_MARK);
}

void test_str_null_new_str_cpy() {
    char *src = "hello world";
    char *new_str = NULL;
    int len = str_cpy(src, new_str, 11);

    assert__("new_str not null", (len == -2));
    assert(len == -2);
    printf("%s Passed test.\n", CHECK_MARK);
}

void test_str_len() {
    char *chr = "this is a sample string.";
    size_t N = 24;

    int len = str_len(chr);

    assert__("not equal length", (len == N));
    assert(len == N);
    printf("%s Passed test.\n", CHECK_MARK);
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

    assert__("not equal length", (len == N));
    assert(len == N);
    printf("%s Passed test.\n", CHECK_MARK);
}

void test_null_string_length() {
    char *string = NULL;

    int len = str_len(string);
    int expected = -1;

    assert__("not null", (len == expected));
    assert(len == expected);
    printf("%s Passed test.\n", CHECK_MARK);
}

void test_str_cat() {
    int N = 10;

    char *src = (char *) malloc(sizeof(char *) * N+1);
    char *append = "cd";

    src[0] = 'a';
    src[1] = 'b';
    src[2] = '\0';

    int len = str_cat(src, append, N, 2);

    assert__("not equal length", (len == 4));
    assert((len == 4));
    printf("%s Passed test.\n", CHECK_MARK);
}

