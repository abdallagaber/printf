#include"main.h"
#include<stdarg>
/**
 * _printf - printf function
 * format: ds sd s sd
 * ...: sd ss sds
 * Return: sd ss s
 */
int _printf(const char *format, ...)
{
va_list arg;
int count = 0, i = 0;

va_start(arg,format);
while(format[i])
{
	if (format[i] == '%')
	{
		i++;
		if (format[i] == 'c')
		{
			_putchar(va_arg(arg, int) + '0');
			count++;
		}
		else if (format[i] == 's')
		{
			count += printf("%s",va_arg(arg, char*));
		}
		else if (format[i] == '%')
		{
			_putchar('%');
			count++;
		}
	}
	else 
	{
		_putchar(format[i]);
		count++;
		i++;
	}
}
return (count);
}
