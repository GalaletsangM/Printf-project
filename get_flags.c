#include "main.h"

int get_flags(const char *format, int *i)
{
    int flags = 0;
    const char *flags_chars = "-+0# ";
    const int flags_values[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE};

    for (int curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        for (int j = 0; flags_chars[j] != '\0'; j++)
        {
            if (format[curr_i] == flags_chars[j])
            {
                flags |= flags_values[j];
                break;
            }
        }

        if (!strchr(flags_chars, format[curr_i]))
            break;
    }

    *i = curr_i - 1;

    return flags;
}
