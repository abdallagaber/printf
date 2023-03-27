#include"main.h"
#include<stdarg.h>
/**
 * _printf - printf function
 * @format: ds sd s sd
 * ...: sd ss sds
 * Return: sd ss s
 */
int _printf(const char *format, ...)
{
va_list arg;
int count = 0, i = 0;

va_start(arg, format);
while (format[i])
{
	if (format[i] == '%')
	{
		i++;
		if (format[i] == 'c')
		{
			_putchar(va_arg(arg, int));
			count++;
		}
		else if (format[i] == 's')
		{
			char *s = va_arg(arg, char*);

			if (s == NULL)
				count += printf("(null)");
			else
			count += printf("%s", s);
		}
		else if (format[i] == '%')
		{
			_putchar('%');
			count++;
		}
		else if (format[i] == 'd' || format[i] == 'i')
			count += printf("%d", va_arg(arg, int));
		else
			return (-1);
		i++;
	}
	else if (format[i] == 92)
	{
		i++;
		if (format[i] == 'n')
			count += _putchar('\n');
	}
	else
	{
		_putchar(format[i]);
		count++;
		i++;
	}}
va_end(arg);
return (count);
}
