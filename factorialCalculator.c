#include <stdio.h>

int factorial(int n);

int main()
{
    int n;
    char ch;

    do
    {
        printf("\n\tFactorials Calculator (n!=?)\t");
        printf("\n\tEnter a non-negative integer: ");

        // Check if input is an integer
        if (scanf("%d", &n) != 1) {
            printf("\n\tInvalid number.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
        else
        {
            // Check if input is non-negative
            while (n < 0) {
                printf("\n\tInvalid number.\n");
                printf("\n\tEnter a non-negative integer: ");
                scanf("%d", &n);
            }

            printf("\n\t\t%d! = %d\n", n, factorial(n));
        }

        printf("\n\tDo you want to try another number? \n\tType Y if yes and N if no:");
        scanf(" %c", &ch);

        if (ch != 'Y' && ch != 'y')
            break;

    } while (ch == 'Y' || ch == 'y');

    printf("\n\tThank you for using my program!");

    return 0;
}

int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}
