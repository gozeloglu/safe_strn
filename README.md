# safe_strn

safe_strn is a C library for safe string operation. It includes some basic string functions to prevent buffer overflow.

### Run

Firstly, compile the code with following command:

```shell
$ gcc lib/*.h lib/*.c test/*.h test/*.c example/*
```

Then, run the executable file.

```shell
$ ./a.out
```

### Usage

```c
#include "safe_string.h"

int main() {
    
    char *src = "hello world";
    char *new_str = (char *) malloc(sizeof(char) * 12); // Allocate memory for string
    str_cpy(src, new_str, 11);  // Copy src to new_str
    
    int len = str_len(new_str); // Length of new_str
    
    char *str1 = "abc";
    char *str2 = "abc";
    int res = str_cmp(str1, str2, 3, 3);
    
    if (res < 0) {
        printf("str1 less than str2\n"): 
    } else if (res > 0){
        printf("str2 less than str1.\n");
    } else {
        printf("str1 and str2 are equal.\n");    // Prints "str1 and str2 are equal."
    }
}
```

### Documentation

```C
int str_cpy(const char *src, char *dst, size_t n));
```

Copies the string from `src` to `dst`. You need to pass length of the string that you want to copy. 

```C
int str_len(const char *s);
```

Returns the length of the string. 

```C
int str_cat(char *src, const char *append, size_t src_size, size_t app_size);
```

Concatenates the given strings. Returns the new length of the `src`. 

```c
int str_cmp(const char *str1, const char *str2, size_t str1_size, size_t str2_size);
```

Compares the two given strings. If `str1` less than `str2`, returns -1. If `str2` less than `str1`, returns 1. And `str1` and `str2` are equal, then returns 0.