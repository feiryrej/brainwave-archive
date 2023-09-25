#include <stdio.h>

int main(){

    int age, loop;
    char ch;

    do {
        printf("Input the age: ");
        scanf("%d", &age);

        if (age < 0 || age > 100000){
            printf("Invalid input!\n");
        }
        else if (age >= 0 && age <= 12){
            printf("C\n");
        }
        else if (age >= 13 && age <= 19){
            printf("T\n");
        }
        else if (age >= 20){
            printf("A\n");
        }
        printf("\nDo you want to check another age? Press Y if yes, Press N if no: ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
        printf("Thank you!");
    return 0;
}
