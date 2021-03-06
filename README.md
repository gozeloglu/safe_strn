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

### Documentation

```C
int str_cpy(const char *src, char *dst, size_t n));
```

Copies the string from `src` to `dst`. You need to pass length of the string that you want to copy. 