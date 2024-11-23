/******************
Name: Yotam Yakov
ID: 207918822
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int choice, number, exit=0;

	do {
		// Print Menu
		printf("Choose an option:\n\
		1. Happy Face\n\
		2. Balanced Number \n\
		3. Generous Number\n\
		4. Circle Of Joy\n\
		5. Happy Numbers \n\
		6. Festival Of Laughter\n\
		7. Exit\n");

		// Choice Input
		scanf("%d", &choice);

		// Uniform input for cases 2-5
		if(choice >= 2 && choice <= 5) {
				printf("Enter a number:\n");
				scanf("%d", &number);
				while(number < 1) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}

		}

		// Menu Switch
		switch (choice){

			// Happy Face
			case 1:
			{
				char eyes, nose, mouth;
				int size=-1;

				//Gather input
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &eyes, &nose, &mouth);
				printf("\nEnter face size:\n");
				scanf(" %d", &size);

				// Validate
				while (size % 2 == 0 || size < 1) {
					printf("\nThe face's size must be an odd and positive number,\n\
					please try again:\n");
					scanf(" %d", &size);
				}

				// Output
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
				// Get Number Length
				int length=0;
				for(int i=number; i > 0; i = i / 10, length++){}

				// Calculate Right Side
				int right = 0, left = 0;
				for(int i = 1; i <= (length / 2); i++) {
					right += number % 10;
					number /= 10;
				}

				// Adjust For Odd Numbers
				if(length % 2 == 1) {
					number /= 10;
				}

				// Calculate Left Side
				for(; number > 0; left += number % 10, number /= 10) {}

				// Output
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
				// Calculate Sum
				int sum=0;
				for(int i = 1; i < number; i++) {
					if(number % i == 0) {
						sum += i;
					}
				}

				// Output
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
				int prime = 1;

				// Check If Prime
				for(int i = 2; i < number; i++) {
					if(number % i == 0) {
						prime = 0;
						break;
					}
				}

				// Output
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
				int digit, temp;

				// Start Of Output
				printf("Between 1 and %d only these numbers bring happiness:\n", number);

				// Calculate Happy Numbers
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

					// Output
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

				// Gather First Input
				printf("Enter a smile and cheer number\n");

				// Validate Input
				while(1) {
					input = scanf(" smile: %d, cheer: %d", &smile, &cheer);

					if(input == 2) {
						break;
					} else {
						printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
						scanf("%[^\n]", &input);
					}
				}

				// Gather Second Input
				printf("Enter maximum number for the festival:\n");
				scanf("%d", &max);
				while(max < 1) {
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d", &max);
				}

				// Output
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
				// Condition For Exit
				exit = 1;
			break;

			default:
			// Validate Choice Input
			printf("This option is not available, please try again\n");
		};
	} while (!exit);

	// Exit Message
	printf("Thank you for your journey through Numeria!\n");

	return 0;
}
