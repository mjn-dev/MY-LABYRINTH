/*
** EPITECH PROJECT, 2025
** includes/my.h header for my own lib
** File description:
** philibert's includes/my.h header
*/
#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stddef.h>
    #include <string.h>
    #include <stdlib.h>
    #define BINARY_BASE "01"
    #define OCTAL_BASE "01234567"
    #define DECIMAL_BASE "0123456789"
    #define HEXADECIMAL_BASE "0123456789ABCDEF"
    #define HEXADECIMAL_BASE_LOWER "0123456789abcdef"
int my_getnbr_parsing(char const *str, int *error);
int my_getnbr(char const *str);
void my_put_nbr(int n, int *count);
void my_putchar(char c, int *count);
int my_putstr(char const *str, int *count);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
void my_swap(int *a, int *b);
char *my_strdup(char const *src);
int my_printf(char const *format, ...);
void my_convert_base(unsigned long nb, char *base, int *count);
void my_put_float(double c, int dec);
void my_put_double(double nb, int *count);
void my_put_scient(double nb, int *count);
int my_return(char *msg, int status);
void my_put_long(long long int n, int *count);
char *my_strchr(const char *s, int c);
char *my_strtok(char *str, const char *delim);
size_t my_strcspn(const char *s, const char *reject);
char *my_revstr(char *str);
int my_putnbr_base(int nbr, char const *base);
void *my_realloc(void *ptr, size_t size_alloc, size_t size);
void *my_memcpy(void *dest, const void *src, size_t n);
int free_and_null(int retval, ...);
void *my_calloc(size_t nmemb, size_t size);
void *my_memset(void *s, int c, size_t n);

void printInt(void *data);
int compareInt(void *a, void *b);
void freeInt(void *data);

#endif /* MY_H_ */
