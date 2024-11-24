/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>
#include <stdlib.h>


int main() {

	// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
	/* Example:
	* n = 3:
	* 0   0
	*   o
	* \___/
	*/

	//check input
		char eye, mouth, nose;
		int face_size;
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
    

	// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
	// and the sum of all digits to the right of the middle digit(s) are equal
	/* Examples:
	Balanced: 1533, 450810, 99
	Not blanced: 1552, 34
	Please notice: the number has to be bigger than 0.
	*/

	//check input
	int num, i, sum = 0;
	printf("jjj\n");
	scanf("%d", &num);
	int clone = num;
	for (i = 0; clone > 0; i++) {
		clone /= 10;
	}
	for (int j = i; j > 0; j--) {
		if (j > i/2)
			sum += num % 10;
		else
			sum -= num %10;
		num /= 10;
	}
	if (sum == 0)
		printf("Balanced\n");
	else
		printf("not\n");






	// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/

	//check input!
	int n, summ = 0;
	scanf("%d", &n);
	for (int i = 1; i < n; i++ ) {
		if (n % i == 0)
			summ += i;
	}
	if (summ > n)
		printf("Great\n");
	else
		printf("Nah\n");



	// Case 4: determine wether a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/

	//check + 1!
    scanf("%d", &n);
	for (int i = 2; i < n/2; i++) {
		if ( n % i == 0) {
			printf("Not prime");
			break;
		}
		else {
			printf("Prime");
		}
	}

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
