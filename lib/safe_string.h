/**
 * Copyright (C) 05.03.2021
 * Author: Gökhan Özeloğlu - <gozeloglu@gmail.com>
 *
 * This file includes the function definitions of
 * the safe_strn library. safe_strn is developed for
 * preventing the buffer overflow.
 *
 * Source code: https://github.com/gozeloglu/safe_strn
 * */

#ifndef SAFE_STRN_SAFE_STRING_H
#define SAFE_STRN_SAFE_STRING_H

#include <stdio.h>
#include <stdlib.h>

/// Copy the string from dst to src
///
/// @param src - source string to be copied
/// @param dst - destination string which the content is to be copied
/// @param n - the number of characters to be copied from source
/// @return integer value the number of copied characters
/// @returns -1 if src is not initialized yet. It has a special purpose
/// @returns -2 if dst is not allocated yet
int str_cpy(const char *src, char *dst, size_t n);


/// Find the length of the given string
///
/// @param s - string to be found length
/// @return int - length of the string
/// @returns -1 if s is not initialized yet. It has a special purpose
int str_len(const char *s);

/// Concatenates the given two strings
///
/// @param src - source string which is being appended
/// @param append - appended string
/// @param src_size - max allocated length
/// @param app_size - appended string length
/// @return length of the new string - src length
/// @returns -1 if src is initialized with NULL
/// @returns -2 if append string is initialized with NULL
/// @returns -3 if there is no enough memory for appending new string
int str_cat(char *src, const char *append, size_t src_size, size_t app_size);

/// Compares the given two strings
///
/// @param str1 - given first string
/// @param str2 - given second string
/// @param str1_size - length of the first string
/// @param str2_size - length of the second string
/// @return -1, 0, or 1 with respect to comparison result
/// @returns -1 if str2 > str1
/// @returns 0 if str1 == str2
/// @returns 1 if str1 > str2
int str_cmp(const char *str1, const char *str2, size_t str1_size, size_t str2_size);
#endif //SAFE_STRN_SAFE_STRING_H
