/**
 * Copyright (C) - 06.03.2021
 * Author: Gökhan Özeloğlu <gozeloglu@gmail.com>
 *
 * Provides interface for test cases.
 *
 * Source code: https://github.com/gozeloglu/safe_strn
 * */

#ifndef SAFE_STRN_TEST_SAFE_STR_LIB_H
#define SAFE_STRN_TEST_SAFE_STR_LIB_H

void test_str_cpy();
void test_src_null_str_cpy();
void test_str_null_new_str_cpy();
void test_str_len();
void test_dynamic_str_len();
void test_null_string_length();
void test_str_cat();
void test_empty_src_str_cat();
void test_empty_append_str_cat();

#endif //SAFE_STRN_TEST_SAFE_STR_LIB_H
