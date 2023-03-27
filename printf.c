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
			i++;
		}
		else if (format[i] == 's')
		{
			char *s = va_arg(arg, char*);
			if (s == NULL)
			{
				count +=printf("(null)");
				i++;
			}
			else
			{
			count += printf("%s", s);
			i++;
			}
		}
		else if (format[i] == '%')
		{
			_putchar('%');
			count++;
			i++;
		}
		else if (format[i] == 'd' || format[i] == 'i')
		{
			count += printf("%d",va_arg(arg, int));
			i++;
		}
		else
		{
			return (-1);
		}
	}
	else
	{
		_putchar(format[i]);
		count++;
		i++;
	}
}
va_end(arg);
return (count);
}
