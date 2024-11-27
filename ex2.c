/******************
Name: Maxim Muradov
ID: 346975386
Assignment: ex2
*******************/
#define ZERO 0
#define PARITY 2
#define BASE 10
#define UNHAPPYLOOP 4

#include <stdio.h>


int main() {

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
				scanf(" %c %c %c", &eye, &nose, &mouth);
				printf("Enter face size: \n");
				scanf("%d", &face_size);

				while((face_size <= ZERO) || (face_size % PARITY == ZERO)) {
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf(" %d", &face_size);
				}

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

			break;

			case 2:
				int i;
				sum = 0;
				printf("Enter a number: \n");
				scanf("%d", &num);
				while (num <= ZERO) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}


				int clone = num;
				for (i = 0; clone > 0; i++) {
						clone /= BASE;
				}

					for (int j = i; j > 0; j--) {
						if (j > i / 2)
							sum += num % BASE;
						else 
							sum -= num % BASE;
						num /= BASE;
					}

					if (sum == ZERO || i == 1)
						printf("This number is balanced and brings harmony!\n");
					else
						printf("This number isn't balanced and destroys harmony.\n");

			break;

			case 3:
				sum = 0;
				printf("Enter a number: \n");
				scanf("%d", &num);
				while(num <= ZERO) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				for (int i = 1; i < num; i++ ) {
					if (num % i == ZERO)
						sum += i;
				}
				if (sum > num)
					printf("This number is generous!\n");
				else
					printf("This number does not share.\n");
			break;

			case 4:
				prime = 0;
				printf("Enter a number: \n");
				scanf("%d", &num);
				while (num <= ZERO) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				int reverse = 0;
				clone = num;
				while (clone > 0){
					reverse *= BASE;
					reverse += clone % BASE;
					clone /= BASE;
				}

				for (int i = 2; i < num/2; i++) {
					if ( num % i == ZERO || reverse % i == ZERO) {
						prime += 1;
						break;
					}
				}

				if (prime == ZERO)
					printf("This number completes the circle of joy!\n");
				else if ((prime > ZERO) || (num == 1))
					printf("The circle remains incomplete.\n");
			break;

			case 5:
				printf("Enter a number: \n");
				scanf("%d", &num);
				while (num <= ZERO) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}

				printf("Between 1 and %d only these numbers bring happiness: ", num);
				for (int i = 1; i <= num; i++) {
					sum = i;
					do {
						chain_num = sum;
						sum = 0;
						for ( ; chain_num > 0 ; chain_num /= BASE) {
							sum += (chain_num % BASE) * (chain_num % BASE);
						}
					} while (sum != 1 && sum != UNHAPPYLOOP);

					if (sum == 1) {
						printf("%d ", i);
					}
				}
			printf("\n");
			break;

			case 6:
				int smile, cheer, max, check;
				check = smile = cheer = 0;
			   	printf("Enter a smile and cheer number:\n");
		                check = scanf("\nsmile: %d , cheer: %d", &smile, &cheer);
		                while (check != 2 || smile == cheer)
		                {
		                    scanf("%*[^\n]%*c");
		                    printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
		                    check = scanf("\nsmile: %d , cheer: %d", &smile, &cheer);
		                }


				
				printf("Enter maximum number for the festival:\n");
				scanf("%d", &max);
				while (max <= ZERO) {
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d", &max);
				}

				for (int i = 1; i <= max; i++ ) {
					if (i % cheer == ZERO && i % smile == ZERO){
						printf("Festival!\n");
					}
					else if (i % smile == ZERO) {
						printf("Smile!\n");
					}
					else if (i % cheer == ZERO) {
						printf("Cheer!\n");
					}
					else {
						printf("%d\n", i);
					}
				}
			break;
		}
	} while (menu != 7);
	printf("Thank you for your journey through Numeria!\n");
	return 0;
}
