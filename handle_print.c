#include "main.h"

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
                 int flags, int width, int precision, int size)
{
    int i, unknown_len = 0;
    const char *valid_fmts = "cs%idbuoxXpSrR";
    
    for (i = 0; valid_fmts[i] != '\0'; i++)
    {
        if (fmt[*ind] == valid_fmts[i])
        {
            if (fmt[*ind] == 'S')
                return print_non_printable(list, buffer, flags, width, precision, size);
            else if (fmt[*ind] == 'r')
                return print_reverse(list, buffer, flags, width, precision, size);
            else if (fmt[*ind] == 'R')
                return print_rot13string(list, buffer, flags, width, precision, size);
            else
                return handle_standard_format(fmt[*ind], list, buffer, flags, width, precision, size);
        }
    }

    if (fmt[*ind] == '\0')
        return -1;

    unknown_len += write(1, "%%", 1);

    if (fmt[*ind - 1] == ' ')
        unknown_len += write(1, " ", 1);
    else if (width)
    {
        --(*ind);
        while (fmt[*ind] != ' ' && fmt[*ind] != '%')
            --(*ind);
        if (fmt[*ind] == ' ')
            --(*ind);
        return 1;
    }

    unknown_len += write(1, &fmt[*ind], 1);

    return unknown_len;
}
