/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday08-tessy.grondin
** File description:
** my
*/

#pragma once
    #include <unistd.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <stdio.h>

#define INT_MAX 2147483647

typedef union c {
    double doub;
    long lon;
} nbru_t;

typedef struct bin_hex_s {
    char *bin;
    char hex;
} bin_hex_t;

typedef struct opening_s {
    int fd;
    struct stat s;
    char *buffer;
    int size;
    char **arg;
}opn_t;

extern const bin_hex_t convert[];

typedef int (*funp_t)(va_list *ap, int prec, int count);
void my_memset(char *src, int len, char set);
char **space_fix(char **src);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
char **my_tabcpy(char **tab);
char *my_str_concat(char *s1, char const *s2);
char *my_fstr_concat(char *dest, char *s1, char const *s2);
void ptr_swap(void *ptr1, void *ptr2);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_isnum(char c);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strcasecmp(char const *s1, char const *s2);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
int my_str_isalpha(char *str);
int my_show_word_array(char *const *tab);
int my_str_islower(char *str);
int my_str_isnum(char *str);
int my_is_printable(char c);
int my_str_isprintable(char *str);
int my_str_isupper(char *str);
int is_upcase(char c);
char *my_strlowcase(char *str);
int is_alphanum(char c);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strstr(char *str, char const *to_find);
int is_low_case(char c);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int my_strlen(char const *str);
char *my_append(char *str, char c);
char **my_tabpop(char **src, int index);
char *my_pop(char *str, int index);
char *my_unappend(char *str);
char **tab_append(char **src, char *add);
char *my_strtok(char *src, char *delim);
char *my_strdup(char const *src);
char *my_fstrdup(char *dest, char const *src);
int my_getnbr_base(char const *str, char const *base);
int my_putchar(char c);
void *can_free(void *ptr);
void *freer(char **tab);
int my_tablen(char **src);
int my_nblen(int nb);
int my_putnbr_base(int nbr, char const *base);
int is_mt(char **src);
int place(char const *str, char c);
int find_smallest(int *array, int size, int start);
char *my_strncat(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
bool is_delim(char c, char *delim);
char **my_str_to_word_array(char *str, char *delim);
char *my_word_array_to_str(char **array, char delim);
int my_put_unsigned(unsigned int nb);
long transform_nb2(double nb, int prec);
int my_putfloat(double nb, int prec);
int my_putfloat_base(double nb, int prec, char const *base);
int my_put_exposant(double nb, int prec, char ex);
int my_put_exposant_base(double nb, int prec, char ex, char const *base);
int my_put_no_trail(double nb, int prec);
int my_put_flaga(double nb, int char_type);
char *my_nb_to_string(long nbr);
char *my_nb_to_string_base(long nbr, char const *base);
bool my_isalpha(char c);
int *chosen_exit(void);
int my_printf(char const *format, ...);
int valid_printf_format(char const *format);
int flags(va_list *ap, int prec, int count);
int flagc(va_list *ap, int prec, int count);
int flagdi(va_list *ap, int prec, int count);
int flagmod(va_list *ap, int prec, int count);
int flagu(va_list *ap, int prec, int count);
int flagp(va_list *ap, int prec, int count);
int flago(va_list *ap, int prec, int count);
int flagx(va_list *ap, int prec, int count);
int flag_x(va_list *ap, int prec, int count);
int flagb(va_list *ap, int prec, int count);
int flagf(va_list *ap, int prec, int count);
int flage(va_list *ap, int prec, int count);
int flag_e(va_list *ap, int prec, int count);
int flagm(va_list *ap, int prec, int count);
int flagg(va_list *ap, int prec, int count);
int flag_g(va_list *ap, int prec, int count);
int flagn(va_list *ap, int prec, int count);
int flaga(va_list *ap, int prec, int count);
int flag_a(va_list *ap, int prec, int count);
char **get_file_content(char *path);
void *free_int(int **nb_tab);
void *my_realloc(size_t size, void *ptr);
int find_smallest_word(char **array);
char **my_sort_word_array(char **array);
int my_intlen(int *src);
int *my_intdup(int *src);
int *append_int(int *src, int add);
bool open_file(opn_t *opn, char *file);
