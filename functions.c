#include "main.h"

/**
 * print_char - Prints a character
 * @types: List of arguments
 * @buffer: Buffer to handle print
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char c = va_arg(types, int);
    return handle_write_char(c, buffer, flags, width, precision, size);
}

/**
 * print_string - Prints a string
 * @types: List of arguments
 * @buffer: Buffer to handle print
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char *str = va_arg(types, char *);
    if (str == NULL)
    {
        str = "(null)";
        if (precision >= 6)
            str = "      ";
    }
    int length = str_length(str, precision);
    return handle_string_print(str, buffer, flags, width, length);
}

/**
 * print_percent - Prints a percent sign
 * @types: List of arguments
 * @buffer: Buffer to handle print
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    UNUSED(types);
    UNUSED(precision);
    UNUSED(size);
    return handle_percent_print(buffer, flags, width);
}

/**
 * print_int - Prints an integer
 * @types: List of arguments
 * @buffer: Buffer to handle print
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    long int n = va_arg(types, long int);
    int is_negative = check_negative(&n);
    return handle_int_print(n, is_negative, buffer, flags, width, precision, size);
}

/**
 * print_binary - Prints a binary number
 * @types: List of arguments
 * @buffer: Buffer to handle print
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    unsigned int n = va_arg(types, unsigned int);
    return handle_binary_print(n, buffer, flags, width, precision, size);
}
