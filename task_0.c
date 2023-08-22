#include "main.h"
#include <stdarg.h>

/**
* _printf - produces output according to a format
* @format: format of output
*
* Return: 0
*/

int _printf(const char *format, ...)
{
	int i;
	char *check;
	va_list list;

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == 'c')
		{
			check = va_arg(list, int);
			fprintf(stdout, format, check);
		}
		if (format[i] == 's')
		{
			check = va_arg(list, char*);
			fprintf(stdout, format, check);
		}
	}
	va_end(list);
	return (0);
}
