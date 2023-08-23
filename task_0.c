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
	char token[1000];
	int k = 0;
	int i;
	va_list list;

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		token[k++] = format[i];
		if (format[i + 1] == '%' || format[i + 1] == '\0')
		{
			token[k] = '\0';
			k = 0;

			if (token[0] != '%')
			{
				fprintf(stdout, "%s", token);
			}
			else
			{
				int j = 1;
				char ch1 = 0;

				while ((ch1 = token[j++] < 58))
				if (ch1 == 'i' || ch1 == 'd')
					fprintf(stdout, token, va_arg(list, int));
				else if (ch1 == 'c')
					fprintf(stdout, token, va_arg(list, int));
				else if (ch1 == 's')
					fprintf(stdout, token, va_arg(list, char*));
				else
					fprintf(stdout, "%s", token);
			}
		}
	}
	va_end(list);
	return (0);
}
