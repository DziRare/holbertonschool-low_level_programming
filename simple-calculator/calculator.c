#include <stdio.h>
/**
 * add - Addition
 * @num_a: First number to add
 * @num_b: Second number to add
 * Description: Finds the sum of two numbers
 * Return: Sum of the two numbers
 */
int add(int num_a, int num_b)
{
	return (num_a + num_b);
}

/**
 * subtract - Subtraction
 * @num_a: Number to subtract from
 * @num_b: Number to subtact
 * Description: Finds the difference of two numbers
 * Return: Difference of the two numbers
 */
int subtract(int num_a, int num_b)
{
	return (num_a - num_b);
}

/**
 * perform_operation - +, -, /, *
 * @operation: The operation that the user would like to perform
 * @a: The first number
 * @b: The second number
 * Description: Run the operation prompted by the user
 * Return: Result of the operation
 */
int perform_operation(int operation, int a, int b)
{
	int result = 0;

	if (operation == 1)
		result = add(a, b);
	else if (operation == 2)
		result = subtract(a, b);
	else
		printf("Operation in progress. Try again later.");

	return (result);
}


/**
 * present_menu - Displays Menu
 * Description: Shows menu and prompts user for operation (+, -, /, *)
 * Return: User's choice of operation
 */
void present_menu(void)
{
	int user_choice;
	int a;
	int b;

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
			printf("Bye!\n");
		}
		else
		{
			printf("A: ");
			scanf("%d", &a);
			printf("B: ");
			scanf("%d", &b);
			printf("Result: %d\n\n", perform_operation(user_choice, a, b));
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
