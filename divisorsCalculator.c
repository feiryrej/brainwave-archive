#include <stdio.h>
#include <stdlib.h>

int KOMPUTE(int N, int *sum)
{
    *sum = 0;
    for (int i = 1; i < N; i++)
        if (N % i == 0)
            *sum = *sum + i;
    if (*sum == N)
        return 1;
    if (*sum > N)
        return 2;
    return 0;
}

int main()
{
    int N, sum;
    char choice;
        printf("\n\tDIVISORS CALCULATOR!\n");
    do {
        printf("\nInput N: ");
        if (scanf("%d", &N) != 1 || N < 1) {
            printf("\n\tInvalid input! Please enter a positive integer.\n");
            while (getchar() != '\n');
            continue;
        }

        int res = KOMPUTE(N, &sum);

        printf("\n\tProper divisors are ");
        for (int i = 1; i < N; i++)
            if (N % i == 0)
                printf("%d ", i);

        printf("\n\tSum of proper divisors: ");
        for (int i = 1; i < N; i++)
            if (N % i == 0)
                printf("%d + ", i);
        printf("= %d\n", sum);

        if (res == 2)
            printf("\t%d > %d is ABUNDANT\n", sum, N);
        else if (res == 1)
            printf("\t%d = %d is PERFECT\n", sum, N);
        else
            printf("\n\t%d < %d is DEFICIENT\n", sum, N);

        printf("\nDo you want to try another number? \nType Y if yes and N if no:");
        if (scanf(" %c", &choice) != 1) {
            printf("\nInvalid input! Please enter 'y' or 'n'.\n");
            choice = 'n';
        }
    } while (choice == 'y' || choice == 'Y');
        printf("\nThank you for using my program!");

    return 0;
}
