#include <stdio.h>

int main(void)
{
    int num1, num2, num3, ch;
    char ch; 
do
{

    printf("Enter three integers: ");
    if (scanf("%d %d %d", &num1, &num2, &num3) != 3)
        {
            printf("Please enter valid integer values!\n");
        }
        else

    if (num1 > num2 && num1 > num3)
    {
        if (num2 > num3)
            printf("The numbers in descending order are: %d %d %d\n", num1, num2, num3);
        else
            printf("The numbers in descending order are: %d %d %d\n", num1, num3, num2);
    }
    else if (num2 > num1 && num2 > num3)
    {
        if (num1 > num3)
            printf("The numbers in descending order are: %d %d %d\n", num2, num1, num3);
        else
            printf("The numbers in descending order are: %d %d %d\n", num2, num3, num1);
    }
    else if (num3 > num1 && num3 > num2)
    {
        if (num1 > num2)
            printf("The numbers in descending order are: %d %d %d\n", num3, num1, num2);
        else
            printf("The numbers in descending order are: %d %d %d\n", num3, num2, num1);
    }
      printf("Do you want to try again? Press Y if yes, Press N if no: ");
        scanf(" %c", &ch);
} while (ch == 'Y' || ch == 'y');
    return 0;
}
