#include <stdio.h>

/**
 * perform_operation - +, -, *, /
 * @operation: The operation that the user would like to perform
 * @a: The first number
 * @b: The second number
 * Description: Run the operation prompted by the user
 * Return: Result of the operation
 */
int perform_operation(int operation, float a, float b)
{
	if (operation == 1)
		printf("Result: %.2f\n\n", a + b);
	else if (operation == 2)
		printf("Result: %.2f\n\n", a - b);
	else if (operation  == 3)
		printf("Result: %.2f\n\n", a * b);
	else if (operation == 4)
		if (b == 0)
			printf("Error: division by zero\n");
		else
			printf("Result: %.2f\n\n", a / b);
	else
		printf("I don't know how we got here. You shouldn't exist.\n");

	return (0);
}

/**
 * present_menu - Displays Menu
 * Description: Shows menu and prompts user for operation (+, -, /, *)
 * Return: User's choice of operation
 */
void present_menu(void)
{
	int user_choice;
	float a;
	float b;

	user_choice = -1;

	printf("Simple Calculator\n\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n\n");

	while (user_choice != 0)
	{
		printf("What operation would you like to perform: ");
		scanf("%d", &user_choice);
		printf("\nChoice: %d\n", user_choice);

		if (user_choice < 0 || user_choice > 4)
		{
			printf("Invalid choice\n\n");
		} else if (user_choice == 0)
		{
			printf("Bye!\n\n");
		}
		else
		{
			printf("A: ");
			scanf("%f", &a);
			printf("B: ");
			scanf("%f", &b);
			perform_operation(user_choice, a, b);
		}

	}
}

/**
 * main - Entry point of calculator
 * Description: Runs the whole calculator program
 * Return: 0 (Success)
 */
int main(void)
{
	present_menu();

	return (0);
}
