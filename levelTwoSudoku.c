#include <stdio.h>

int main() {
    int num1, num2, num3;
    char answer;

        //ask user to input 3 different numbers
    do {
        printf("\n\t\t WELCOME TO SUDOKU!!\n\n");
        printf("\n\tEnter 3 different numbers (from 1-9) that add up to 9\n\n");
        printf("   First number:  ");
        scanf("%d", &num1);
        printf("   Second number: ");
        scanf("%d", &num2);
        printf("   Third number:  ");
        scanf("%d", &num3);

        // check if numbers are different add up to 9
        if (num1 != 0 && num2 != 0 && num3 != 0 && num1 != num2 && num1 != num3 && num2 != num3 && num1 + num2 + num3 == 9) {
            printf("\n");
            printf("\t+-------+-------+-------+\n");
            printf("\t| %-2d    | %-2d    | %-2d    |\n", num1, num2, num3);
            printf("\t|       |       |       |\n");
            printf("\t+-------+-------+-------+\n");
            printf("\t| %-2d    | %-2d    | %-2d    |\n", num2, num3, num1);
            printf("\t|       |       |       |\n");
            printf("\t+-------+-------+-------+\n");
            printf("\t| %-2d    | %-2d    | %-2d    |\n", num3, num1, num2);
            printf("\t|       |       |       |\n");
            printf("\t+-------+-------+-------+\n");
            printf("\n");
        } else {
            printf("   \n\nInvalid input. Please enter 3 different numbers (from 1-9) that add up to 9.\n");
            continue;
        }

        // ask user if they want to run the program again
        printf("   \nDo you want to enter another set of numbers?");
        printf("   \n[y] Yes");
        printf("   \n[n] No");
        printf("   \nAnswer here: ");
        scanf(" %c", &answer);
    } while (answer == 'y' || answer == 'Y');

    return 0;
}
