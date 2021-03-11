/**
 * Copyright (C) 05.03.2021
 * Author: Gökhan Özeloğlu - <gozeloglu@gmail.com>
 *
 * This file includes the implementations of the safe_strn
 * functions.
 *
 * Source code - https://github.com/gozeloglu/safe_strn
 * */

#include "safe_string.h"

int str_cpy(const char* src, char* dst, size_t n) {
    int i = 0;
    while (i < n && src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';

    return i;
}