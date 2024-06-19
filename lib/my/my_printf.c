/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** mini_printf
*/

#include "../../include/my.h"

int *chosen_exit(void)
{
    static int res = 1;

    return &res;
}

int find_prec(char const *format, int index)
{
    if (format[index] != '.')
        return 6;
    return my_getnbr(format + index + 1);
}

int focus_on_flag(char const *format, int index)
{
    int i = 1;

    if (format[index] != '.')
        return 0;
    for (; my_isnum(format[index + i]); i++);
    return i;
}

int type_list(char const *format, int *index, va_list *ap)
{
    char ref[] = "scid%xXobupmfFeEgGnaA";
    funp_t func[] = {&flags, &flagc, &flagdi, &flagdi, &flagmod, &flagx,
    &flag_x, &flago, &flagb, &flagu, &flagp, &flagm, &flagf, &flagf,
    &flage, &flag_e, &flagg, flag_g, &flagn, &flaga, &flag_a};
    int prec = find_prec(format, *(index));

    *(index) += focus_on_flag(format, *(index));
    for (int i = 0; ref[i]; i++)
        if (format[*(index)] == ref[i])
            return func[i](ap, prec, *index);
    return my_putchar('%') + my_putchar(format[*(index)]);
}

int my_printf(const char *format, ...)
{
    int res = 0;
    va_list ap;
    int *ex = chosen_exit();

    if (format == NULL)
        return 0;
    va_start(ap, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] != '%')
            res += my_putchar(format[i]);
        if (format[i] == '%') {
            i++;
            res += type_list(format, &i, &ap);
        }
    }
    va_end(ap);
    *ex = 1;
    return res * valid_printf_format(format);
}
