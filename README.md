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
    char *new_str = (char *) malloc(sizeof(char) * 12);
    int len = str_cpy(src, new_str, 11);
}
```

### Documentation

```C
int str_cpy(const char *src, char *dst, size_t n));
```

Copies the string from `src` to `dst`. You need to pass length of the string that you want to copy. 