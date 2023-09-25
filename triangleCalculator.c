#include <stdio.h>
#include <stdlib.h>

void TRIANGLE(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Invalid input: sides must be positive\n");
    } else if (a == b && b == c) {
        printf("\n\t\tThe triangle is EQUILATERAL\n");
    } else if (a == b || b == c || c == a) {
        printf("\n\t\tThe triangle is ISOSCELES\n");
    } else {
        printf("\n\t\tThe triangle is SCALENE\n");
    }
}

int main() {
    int a, b, c;
    char choice;
    printf("\n\t\tTriangle Calculator!\n");

    do {
        int invalid_input = 0;
        do {
            printf("\tEnter the length of the three sides of the triangle\n");
            printf("\nEnter the length of side [1]: ");
            if (scanf("%d", &a) != 1) {
                printf("\n\tInvalid input: please enter a number\n");
                invalid_input = 1;
                while (getchar() != '\n'); // consume the remaining characters in the input buffer
            } else if (a <= 0) {
                printf("\n\tInvalid input: sides must be positive\n");
                invalid_input = 1;
            } else {
                invalid_input = 0;
            }
        } while (invalid_input);

        do {
            printf("Enter the length of side [2]: ");
            if (scanf("%d", &b) != 1) {
                printf("\n\tInvalid input: please enter a number\n");
                invalid_input = 1;
                while (getchar() != '\n'); // consume the remaining characters in the input buffer
            } else if (b <= 0) {
                printf("\n\tInvalid input: sides must be positive\n");
                invalid_input = 1;
            } else {
                invalid_input = 0;
            }
        } while (invalid_input);

        do {
            printf("Enter the length of side [3]: ");
            if (scanf("%d", &c) != 1) {
                printf("\n\tInvalid input: please enter a number\n");
                invalid_input = 1;
                while (getchar() != '\n'); // consume the remaining characters in the input buffer
            } else if (c <= 0) {
                printf("\n\tInvalid input: sides must be positive\n");
                invalid_input = 1;
            } else {
                invalid_input = 0;
            }
        } while (invalid_input);

        printf("The sides of the triangle are: %d, %d, %d\n", a, b, c);
        TRIANGLE(a, b, c);

         printf("\nDo you want to try another triangle? \nType Y if yes and N if no:");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
        printf("\nThank you for using my program!");

    return 0;
}
