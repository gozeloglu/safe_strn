/**
 * Copyright (C) - 06.03.2021
 * Author: Gökhan Özeloğlu <gozeloglu@gmail.com>
 *
 * Provide util functions.
 *
 * Source code: https://github.com/gozeloglu/safe_strn
 * */

#ifndef SAFE_STRN_UTIL_H
#define SAFE_STRN_UTIL_H

#define CHECK_MARK "\U00002713"
#define CROSS_MARK "\U0000274C"
#define assert__(msg, x) {if (!x) {printf("%s %s\n", CROSS_MARK,msg); assert(x);} }

#endif //SAFE_STRN_UTIL_H
