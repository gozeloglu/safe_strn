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

int str_cmp(const char *str1, const char *str2, size_t str1_size, size_t str2_size) {

    // Check str1 is NULL or not
    // If both strings are NULL, then return 0
    // 0 means equal strings
    // If only str1 is NULL, then second str
    // is ahead of the first string
    if (str1 == NULL) {
        return str2 == NULL ? 0 : -1;
    }

    // If str2 is NULL, then, automatically
    // str1 is ahead of the second str
    if (str2 == NULL) {
        return 1;
    }

    // If str1 and str2 characters are not equal,
    // compare the chars.
    // If str1 char is bigger than str2 in ASCII values,
    // return 1, otherwise -1.
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && i < str1_size && i < str2_size) {
        if (str1[i] != str2[i]) {
            return str1[i] > str2[i] ? 1 : -1;
        }
        i++;
    }

    // If both str1 and str2 are reached out the
    // end of strings, then return 0 which means
    // both strings are equal.
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    }

    // Check again last character ASCII values
    return str1[i] > str2[i] ? 1 : -1;
}

char *str_mk(const char *str, size_t str_len) {
    if (str_len+1 > UINT_MAX) {
        char *s = (char *) malloc(sizeof(char *) * UINT_MAX);
        int i;
        for (i = 0; i < UINT_MAX-1; i++) {
            s[i] = str[i];
        }
        s[i] = '\0';
        return s;
    }

    char *s = (char *) malloc(sizeof(char *) * str_len+1);
    int i = 0;
    while (str[i] != '\0' && i < str_len) {
        s[i] = str[i];
        i++;
    }
    s[i] = '\0';

    return s;
}
