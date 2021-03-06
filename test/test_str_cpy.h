/**
 * Copyright (C) - 06.03.2021
 * Author: Gökhan Özeloğlu <gozeloglu@gmail.com>
 *
 * Test for str_cpy function.
 *
 * Source code: https://github.com/gozeloglu/safe_strn
 * */

#ifndef SAFE_STRN_TEST_STR_CPY_H
#define SAFE_STRN_TEST_STR_CPY_H

#define CHECK_MARK "\U00002713"
#define CROSS_MARK "\U0000274C"
#define assert__(msg, x) {if (!x) {printf("%s %s\n", CROSS_MARK,msg); assert(x);} }

void test_str_cpy();

#endif //SAFE_STRN_TEST_STR_CPY_H
