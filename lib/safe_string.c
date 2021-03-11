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

    // Check the src is NULL or not
    // -1 means src string is not initialized yet
    if (src == NULL) {
        return -1;
    }

    // Check the dst is NULL or not
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
    // If it is NULL, return -1
    // So, -1 means it is declared with NULL
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

int str_cat(char *src, const char *append, size_t src_size, size_t app_size) {

    // Check the src is declared with NULL or not
    // If NULL is assigned, returns -1
    // -1 means NULL is assigned for src
    if (src == NULL) {
        return -1;
    }

    // Check the append is declared with NULL or not
    // If NULL is assigned, returns -2
    // -2 means NULL is assigned for append
    if (append == NULL) {
        return -2;
    }

    // Check whether there is enough length for appending new string
    // -3 means no space in src string
    int len_src = str_len(src);
    if (len_src == src_size) {
        return -3;
    }

    // Start with end of src
    // Append char by char at each step
    // If length of src or append exceeds,
    // then terminate the append
    // free appended string
    int i = len_src;
    int j = 0;
    while (i != src_size && append[j] != '\0' && j != app_size) {
        src[i] = append[j];
        i++;
        j++;
    }
    src[i] = '\0';

    return i;
}
