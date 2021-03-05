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

int str_cpy(const char *src, char *dst, size_t s_size);
int str_len(const char *s);
int str_cat(char *src, char *append, size_t src_size, size_t dst_size);

#endif //SAFE_STRN_SAFE_STRING_H
