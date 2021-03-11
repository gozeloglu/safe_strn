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
int str_cpy(const char *src, char *dst, size_t n);


/// Find the length of the given string
///
/// @param s - string to be found length
/// @return size_t - length of the string
int str_len(const char *s);
int str_cat(char *src, char *append, size_t src_size, size_t dst_size);

#endif //SAFE_STRN_SAFE_STRING_H
