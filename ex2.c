/******************
Name: Maxim Muradov
ID: 346975386
Assignment: ex2
*******************/

#include <stdio.h>


int main() {
	/*
		// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
		/* Example:
		* n = 3:
		* 0   0
		*   o
		* \___/
		*/

	//check input
	char eye, mouth, nose;
	int menu, num, sum, face_size, prime, chain_num;

	do {

		printf("Choose an option:\n1. Happy Face\n2. Balanced Number\n3. Generous Number\n4. Circle Of Joy\n5. Happy Numbers\n6. Festival Of Laughter\n7. Exit\n");
		scanf("%d", &menu);
		while (menu < 1 || menu > 7) {
			printf("This option is not available, please try again.\n");
			scanf("%d", &menu);
		}

		switch (menu){

			case 1:
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf("%c %c %c", &eye, &nose, &mouth);
				printf("Enter face size:\n");
				scanf("%d", &face_size);
				if ((face_size <= 0) || (face_size % 2 == 0)) {
					printf("The face's size must be an odd and positive number, please try again:\n");
				}
				else {
					printf("%c", eye);
					for (int i = 0; i < face_size; i++)
						printf(" ");
					printf("%c\n", eye);

					for (int i = 0; i < face_size; i++)
						if (i == (face_size+2)/2)
							printf("%c", nose);
						else
							printf(" ");
					printf("\n");

					printf( "\\");
					for (int i = 0; i < face_size; i++)
						printf("%c", mouth);
					printf("/\n");
				}
			break;


			// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
			// and the sum of all digits to the right of the middle digit(s) are equal
			/* Examples:
			Balanced: 1533, 450810, 99
			Not blanced: 1552, 34
			Please notice: the number has to be bigger than 0.
			*/

			//check input
			case 2:
				int i;
				sum = 0;
				printf("Enter a number: \n");

				do {
					scanf("%d", &num);
					printf("Only positive number is allowed, please try again:\n");
				} while (num <= 0);

				int clone = num;
				for (i = 0; clone > 0; i++) {
						clone /= 10;
				}

					for (int j = i; j > 0; j--) {
						if (j > i / 2)
							sum += num % 10;
						else {
							sum -= num % 10;
							num /= 10;
						}
					}

					if (sum == 0)
						printf("This number is balanced and brings harmony!\n");
					else
						printf("This number isn't balanced and destroys harmony.\n");

			break;






			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			/* Examples:
			Abudant: 12, 20, 24
			Not Abudant: 3, 7, 10
			Please notice: the number has to be bigger than 0.
			*/

			case 3:
				sum = 0;
				printf("Enter a number: \n");
				do {
					scanf("%d", &num);
					if (num <= 0)
						printf("Only positive number is allowed, please try again:\n");
				} while (num <= 0);
				for (int i = 1; i < num; i++ ) {
					if (num % i == 0)
						sum += i;
				}
				if (sum > num)
					printf("This number is generous!\n");
				else
					printf("This number does not share.\n");
			break;


			// Case 4: determine wether a number is a prime.
			/* Examples:
			This one brings joy: 3, 5, 11
			This one does not bring joy: 15, 8, 99
			Please notice: the number has to be bigger than 0.
			*/

			//check + 1!
			case 4:
				prime = 0;

				do {
					scanf("%d", &num);
					if (num <= 0)
						printf("Only positive number is allowed, please try again:\n");
				} while (num <= 0);

				for (int i = 2; i < num/2; i++) {
					if ( num % i == 0) {
						prime += 1;
						break;
					}
				}

				if (prime == 0)
					printf("This number completes the circle of joy!\n");
				else if ((prime > 0) || (num == 1))
					printf("The circle remains incomplete.\n");
			break;

			// Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.*/
			case 5:
				scanf("%d", &num);
				while (num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}

				printf("Between 1 and %d only these numbers bring happiness: ", num);
				for (int i = 1; i <= num; i++) {
					sum = i;
					do {
						chain_num = sum;
						sum = 0;
						for ( ; chain_num > 0 ; chain_num /= 10) {
							sum += (chain_num % 10) * (chain_num % 10);
						}
					} while (sum != 1 && sum != 4);

					if (sum == 1) {
						printf("%d", i);
					}
				}
			break;




			// Festival of Laughter: Prints all the numbers between 1 the given number:
			// and replace with "Smile!" every number that divided by the given smile number
			// and replace with "Cheer!" every number that divided by the given cheer number
			// and replace with "Festival!" every number that divided by both of them
			/* Example:
			6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
			*/

			// char str[128];
			// char key[128] = {s,m,i,l,e,':', ,c,h,e,e,r,':'};
			case 6:
				int smile, cheer, max;
				int check = scanf("smile: %d, cheer: %d",&smile,&cheer);
				while (check != 2 && smile <= 0 && cheer <= 0){
					scanf("%[^\n]%*с");
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
				}
				printf("Enter maximum number for the festival:\n");
				scanf("%d", &max);
				while (max <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &max);
				}

				for (int i = 1; i <= max; i++ ) {
					if (i % smile == 0) {
						printf("smile");
					}
					else if (i % cheer == 0) {
						printf("cheer");
					}
					else if (i % cheer == 0 && i % smile == 0){
						printf("Festival");
					}
					else {
						printf("%d", i);
					}
				}
			break;
		}
	} while (menu != 7);
	printf("Thank you for your journey through Numeria!\n");
	return 0;
}
