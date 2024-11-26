/******************
Name: Maxim Muradov
ID: 346975386
Assignment: ex2
*******************/

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

				while((face_size <= 0) || (face_size % 2 == 0)) {
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
				while (num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}


				int clone = num;
				for (i = 0; clone > 0; i++) {
						clone /= 10;
				}

					for (int j = i; j > 0; j--) {
						if (j > i / 2)
							sum += num % 10;
						else 
							sum -= num % 10;
						num /= 10;
					}

					if (sum == 0 || i == 1)
						printf("This number is balanced and brings harmony!\n");
					else
						printf("This number isn't balanced and destroys harmony.\n");

			break;

			case 3:
				sum = 0;
				printf("Enter a number: \n");
				scanf("%d", &num);
				while(num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				for (int i = 1; i < num; i++ ) {
					if (num % i == 0)
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
				while (num <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				int reverse = 0;
				clone = num;
				while (clone > 0){
					reverse *= 10;
					reverse += clone % 10;
					clone /= 10;
				}

				for (int i = 2; i < num/2; i++) {
					if ( num % i == 0 || reverse % i == 0) {
						prime += 1;
						break;
					}
				}

				if (prime == 0)
					printf("This number completes the circle of joy!\n");
				else if ((prime > 0) || (num == 1))
					printf("The circle remains incomplete.\n");
			break;

			case 5:
				printf("Enter a number: \n");
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
						printf("%d ", i);
					}
				}
			printf("\n");
			break;

			case 6:
				int smile, cheer, max;
				    printf("Enter a smile and cheer number:\n");
				    int check;
				    do {
				        char input[128];
				        fgets(input, sizeof(input), stdin); // Read full line including spaces
				        check = sscanf(input, "smile: %d, cheer: %d", &smile, &cheer);
				
				        if (check != 2 || smile <= 0 || cheer <= 0) {
				            printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
				        }
				    } while (check != 2 || smile <= 0 || cheer <= 0);
				

				
				printf("Enter maximum number for the festival:\n");
				scanf("%d", &max);
				while (max <= 0) {
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d", &max);
				}

				for (int i = 1; i <= max; i++ ) {
					if (i % cheer == 0 && i % smile == 0){
						printf("Festival!\n");
					}
					else if (i % smile == 0) {
						printf("Smile\n");
					}
					else if (i % cheer == 0) {
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
