#include"main.h"
#include<stdarg.h>
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
			_putchar(va_arg(arg, int));
			count++;
			i++;
		}
		else if (format[i] == 's')
		{
			char *s = va_arg(arg, char*);
			printf("%s",s);
			i++;
			count += strlen(s);
		}
		else if (format[i] == '%')
		{
			_putchar('%');
			count++;
			i++;
		}
		else 
		{
			i++;
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
