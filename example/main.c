/**
 * Copyright (C) - 05.03.2021
 * Auhor: Gökhan Özeloğlu - <gozeloglu@gmail.com>
 *
 * This file includes test functions for safe_strn library
 *
 * Source code: https://github.com/gozeloglu/safe_strn
 * */

#include "../lib/safe_string.h"

int main() {
    char *src = "Hello";
    char *dst = (char *) malloc(sizeof(char *) * 5);

    int len = str_cpy(src, dst, 2);
    printf("copied str(%s) len: %d\n", dst, len);
}