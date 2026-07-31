#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * select_type - Determine which type is going to be passed through
 * @print_list: List of arguments to print
 * @type: Data type to check for
 *
 * Return: No return value
 */
int select_type(va_list *print_list, char type)
{
	char char_item;
	int int_item;
	float float_item;
	char *str_item;

	switch (type)
	{
		case ('c'):
			char_item = va_arg(*print_list, int);
			printf("%c", char_item);
			return (0);
		case ('i'):
			int_item = va_arg(*print_list, int);
			printf("%d", int_item);
			return (0);
		case ('f'):
			float_item = va_arg(*print_list, double);
			printf("%f", float_item);
			return (0);
		case ('s'):
			str_item = va_arg(*print_list, char *);
			if (str_item == NULL)
			{
				printf("(nil)");
				return (0);
			}
			printf("%s", str_item);
			return (0);
		default:
			return (1);
	}
}

/**
 * print_all - Prints anything
 * @format: List of types of arguments
 *
 * Return: No return value
 */
void print_all(const char * const format, ...)
{
	va_list list;
	int index;
	char current_type;
	int skip;

	va_start(list, format);
	index = 0;
	while (format != NULL && format[index] != '\0')
	{
		current_type = format[index];
		skip = select_type(&list, current_type);
		if (format[index + 1] != '\0' && !skip)
		{
			printf(", ");
		}
		index++;
	}
	printf("\n");
	va_end(list);
}
