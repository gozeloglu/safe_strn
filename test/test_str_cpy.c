/**
 * Copyright (C) - 06.03.2021
 * Author: Gökhan Özeloğlu <gozeloglu@gmail.com>
 *
 * Implementation of the test_str_cpy.h
 *
 * Source code: https://github.com/gozeloglu/safe_strn
 * */

#include <assert.h>
#include "test_str_cpy.h"
#include "../lib/safe_string.h"

void test_str_cpy() {
    char *src = "hello world";
    char *new_str = (char *) malloc(sizeof(char) * 12);
    int len = str_cpy(src, new_str, 11);

    assert__("wrong len", (len == 11));
    assert(new_str[11] == src[11]);
    printf("%s Passed test.\n", CHECK_MARK);
}
