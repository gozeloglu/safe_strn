# safe_strn

safe_strn is a C library for safe string operation. It includes some basic string functions to prevent buffer overflow.

```C
int str_cpy(const char *src, char *dst, size_t n));
```

Copies the string from `src` to `dst`. You need to pass length of the string that you want to copy. 