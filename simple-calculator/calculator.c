#include <stdio.h>

/**
 * present_menu - Displays Menu
 * Description: Shows menu and prompts user for operation (+, -, /, *)
 * Return: User's choice of operation
 */
int present_menu(void)
{
	int user_choice;
	user_choice = -1;

	printf("Simple Calculator\n\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n\n");

	while (user_choice < 0 || user_choice > 4)
	{
		printf("What operation would you like to perform: ");
		scanf("%d", &user_choice);
		printf("Choice: %d\n", user_choice);

		if (user_choice < 0 || user_choice > 4)
			printf("Invalid choice\n");
			
	}

	if (user_choice == 0)
		printf("Bye!\n");

	return (user_choice);
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
