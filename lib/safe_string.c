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

    // Check the src is initialized or not
    // -1 means src string is not initialized yet
    if (src == NULL) {
        return -1;
    }

    // Check the dst is initialized or not
    // -2 means dst string is not initialized yet
    if (dst == NULL) {
        return -2;
    }

    // Go until reaching n or null terminator
    // Copy char by char
    int i = 0;
    while (i < n && src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';

    return i;
}

int str_len(const char *s) {

    // Check the char pointer
    // If it is null, return -1
    // So, -1 means it is declared but
    // not assigned
    if (s == NULL) {
        return -1;
    }

    // Go until finding null terminator
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }

    return i;
}