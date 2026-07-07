#include "main.h"
#include <stdio.h>

/**
 * jack_bauer - 24 Hours
 * Description: Prints every minute of the day, starting from 00:00 to 23:59.
 * Return: 0 (Success)
 */
void jack_bauer(void)
{
	int hour_10s;
	int hour_1s;
	int minute_10s;
	int minute_1s;

	/* First Digit */
	for (hour_10s = 48; hour_10s < 51; hour_10s++)
	{
		/* Second Digit */
		for (hour_1s = 48; hour_1s < 58; hour_1s++)
		{
			if (hour_10s == 50 && hour_1s == 52)
				break;
			/* Third Digit */
			for (minute_10s = 48; minute_10s < 54; minute_10s++)
			{
				/* Fourth Digit */
				for (minute_1s = 48; minute_1s < 58; minute_1s++)
				{
					_putchar(hour_10s);
					_putchar(hour_1s);
					_putchar(58);
					_putchar(minute_10s);
					_putchar(minute_1s);
					_putchar('\n');
				}
			}
		}
	}
}
