#include <stdio.h>
#include <ctype.h>

/**
 * perform_operation - +, -, *, /
 * @operation: The operation that the user would like to perform
 * @a: The first number
 * @b: The second number
 * Description: Run the operation prompted by the user
 * Return: Result of the operation
 */
void perform_operation(int operation, float a, float b)
{
	if (operation == 1)
		printf("Result: %.2f\n\n", a + b);
	else if (operation == 2)
		printf("Result: %.2f\n\n", a - b);
	else if (operation  == 3)
		printf("Result: %.2f\n\n", a * b);
	else if (operation == 4)
		if (b == 0)
			printf("Error: division by zero\n\n");
		else
			printf("Result: %.2f\n\n", a / b);
	else
		printf("I don't know how we got here. You shouldn't exist.\n");
}

/**
 * input_numbers - Numbers Used
 * @place: First or second number being validated
 * Description: Validates the numbers the user would like to calculate
 * Return: Returns number user has chosen
 */
float input_numbers(char place)
{
	int invalid;
	float num;
	char final_char;
	int clear;

	invalid = 1;

	while (invalid == 1)
	{
		printf("Enter number %c: ", place);
		if (scanf("%f%c", &num, &final_char) != 2 || final_char != '\n')
		{
			printf("Invalid number!\n\n");

			/* Empty stdin */
			clear = getchar();
			while (clear != '\n' && clear != EOF)
				clear = getchar();
		}
		else
		{
		invalid = 0;
		}
	}

	return (num);
}

/**
 * user_choice - Validates User's Operation Choice
 * Description: Ensures that the choice of operation is valid (+, -, /, *)
 * Return: User's choice of operation
 */
int user_choice(void)
{
	int operation;
	char final_char;
	int clear;

	operation = 9;

	while (operation != 0)
	{
		printf("What operation would you like to perform: ");
		if (scanf("%d%c", &operation, &final_char) != 2 || final_char != '\n')
		{
			printf("Invalid choice!\n\n");

			/* Clear stdin*/
			clear = getchar();
			while (clear != '\n' && clear != EOF)
				clear = getchar();
		}
		else
		{
			printf("\nChoice: %d\n", operation);
			if (operation < 0 || operation > 4)
				printf("Invalid choice\n\n");
			else
				return (operation);
		}
	}
	return (operation);
}

/**
 * main - Entry point of calculator
 * Description: Runs the whole calculator program
 * Return: 0 (Success)
 */
int main(void)
{
	int operation = -1;

	float a;
	float b;

	printf("Simple Calculator\n\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n\n");

	while (1)
	{
		/* Validate User Choice */
		operation = user_choice();
		if (operation == 0)
		{
			printf("Bye! Bye!\n\n");
			return (0);
		}

		/* Retrieve and validate numbers to calculate */

		a = input_numbers('A');
		b = input_numbers('B');

		perform_operation(operation, a, b);
	}
}

