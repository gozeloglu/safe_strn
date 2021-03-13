/**
 * Copyright (C) - 05.03.2021
 * Auhor: Gökhan Özeloğlu - <gozeloglu@gmail.com>
 *
 * This file includes test functions for safe_strn library
 *
 * Source code: https://github.com/gozeloglu/safe_strn
 * */

#include "../test/test_safe_str_lib.h"

int main() {

    test_str_cpy();
    test_src_null_str_cpy();
    test_str_null_new_str_cpy();
    test_str_len();
    test_dynamic_str_len();
    test_null_string_length();
    test_str_cat();
    test_empty_src_str_cat();
    test_empty_append_str_cat();
    test_str_cmp();
    test_not_equal_str_cmp();
    test_not_equal_str2_cmp();
    test_empty_str_cmp();
    test_null_str_cmp();
    test_both_null_str_cmp();
    test_str_mk();
    test_empty_str_mk();
    test_less_mem_str_mk();
    test_static_str_cpy();
    test_static_str_len();
    test_static_str_cat();
    test_static_str_cmp();
}
