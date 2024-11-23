/******************
Name: Yotam Yakov
ID: 207918822
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int choice, number, exit=0;
	do {
		printf("Choose an option:\n\
		1. Happy Face\n\
		2. Balanced Number \n\
		3. Generous Number\n\
		4. Circle Of Joy\n\
		5. Happy Numbers \n\
		6. Festival Of Laughter\n\
		7. Exit\n");
		scanf("%d", &choice);
		switch (choice){
			// Happy Face
			case 1:
			{
				char eyes, nose, mouth;
				int size=-1;

				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &eyes, &nose, &mouth);
				printf("\nEnter face size:\n");
				scanf(" %d", &size);

				while (size % 2 == 0 || size < 1) {
					printf("\nThe face's size must be an odd and positive number,\n\
					please try again:\n");
					scanf(" %d", &size);
				}

				printf("%c", eyes);
				for(int i = 0; i < size; i++)
					printf(" ");
				printf("%c\n", eyes);

				for(int i = 0; i <= size; i += 2)
					printf(" ");
				printf("%c\n", nose);

				printf("\\");
				for(int i = 0; i < size; i++)
					printf("%c", mouth);
				printf("/\n");
			break;
		}

			// Balanced Number
			case 2:
			{
				printf("Enter a number:\n");
				scanf("%d", &number);
				while(number < 1) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}

				int length=0;
				for(int i=number; i > 0; i = i / 10, length++){}

				int right = 0, left = 0;
				for(int i = 1; i <= (length / 2); i++) {
					right += number % 10;
					number /= 10;
				}

				if(length % 2 == 1) {
					number /= 10;
				}

				for(; number > 0; left += number % 10, number /= 10) {}

				if(right == left) {
					printf("This number is balanced and brings harmony!\n");
				} else {
					printf("This number isn't balanced and destroys harmony.\n");
				}
				
			break;
			}
			
			// Generous Number
			case 3:
			{
				printf("Enter a number:\n");
				scanf("%d", &number);
				while(number < 1) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}

				int sum=0;
				for(int i = 1; i < number; i++) {
					if(number % i == 0) {
						sum += i;
					}
				}
				if(sum > number) {
					printf("This number is generous!\n");
				} else {
					printf("This number does not share.\n");
				}
			break;
			}

			// Circle Of Joy
			case 4:
			{
				printf("Enter a number:\n");
				scanf("%d", &number);
				while(number < 1) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}

				int prime=1;
				for(int i=2; i < number; i++) {
					if(number % i == 0) {
						prime = 0;
						break;
					}
				}

				if(prime) {
					printf("This number completes the circle of joy!\n");
				} else {
					printf("The circle remains incomplete.\n");
				}
				break;
			}
		
			// Happy Numbers
			case 5:
			{
				printf("Enter a number:\n");
				scanf("%d", &number);
				while(number < 1) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}

				int digit, temp;
				printf("Between 1 and %d only these numbers bring happiness:\n", number);

				for(int i = 1, sum; i <= number; i++) {
					sum = i;
					while(sum >= 10) {
						temp = 0;
						while(sum > 0) {
						digit = sum % 10;
						digit *= digit;
						temp += digit;
						sum /= 10;
						}
					sum = temp;
					}

					if(sum == 1 || sum == 7) {
						printf("%d ", i);
					}
				}
				printf("\n");
				break;
			}

			// Festival Of Laughter
			case 6:
			{
				int input, smile, cheer, max;
				printf("Enter a smile and cheer number\n");

				while(1) {
					input = scanf(" smile: %d, cheer: %d", &smile, &cheer);

					if(input == 2) {
						break;
					} else {
						printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
						scanf("%[^\n]", &input);
					}
				}

				printf("Enter maximum number for the festival:\n");
				scanf("%d", &max);
				while(max < 1) {
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d", &max);
				}

				for(int i = 1; i <= max; i++) {
					if(i % smile == 0) {
						if(i % cheer == 0) {
							printf("Festival!\n");
						} else {
							printf("Smile!\n");
						}
					} else {
						if(i % cheer == 0) {
							printf("Cheer\n");
						} else {
							printf("%d\n", i);
						}
					}
				}

				break;
			}

			case 7:
				exit = 1;
			break;
			default:
			printf("This option is not available, please try again\n");
		};
	} while (!exit);
	printf("Thank you for your journey through Numeria!\n");

	// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
	/* Example:
	* n = 3:
	* 0   0
	*   o
	* \___/
	*/
    

	// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
	// and the sum of all digits to the right of the middle digit(s) are equal
	/* Examples:
	Balanced: 1533, 450810, 99
	Not blanced: 1552, 34
	Please notice: the number has to be bigger than 0.
	*/
	
	// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/

	// Case 4: determine wether a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/
    

	// Happy numbers: Print all the happy numbers between 1 to the given number.
	// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
	/* Examples:
	Happy :) : 7, 10
	Not Happy :( : 5, 9
	Please notice: the number has to be bigger than 0.
	*/

	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/
	return 0;
}
