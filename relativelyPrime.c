#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int rel_prime(int i, int j)
{
    int k;
    for (k = 2; k <= i && k <= j; k++)
    {
        if (i % k == 0 && j % k == 0)
            return 0;
    }
    return 1;
}

int get_positive_int(const char* prompt)
{
    int n;
    char buf[256];
    while (1) {
        printf("%s", prompt);
        fgets(buf, sizeof(buf), stdin);
        if (sscanf(buf, "%d", &n) == 1 && n > 0)
            break;
        printf("Invalid input, please enter a positive integer\n");
    }
    return n;
}

int main()
{
    int i, j;
    char ch;
    do {
    printf("\n\tRelatively Prime Numbers Calculator\t");
    printf("\n\t\tInput two integers");
    printf("\n\n\tFirst Integer:");
    while (scanf("%d", &i) != 1 || i <= 0) {
        while (getchar() != '\n'); // Clear input buffer
        printf("\n\tPlease enter a positive integer\n");
        printf("\n\tFirst Integer:");
    }
    printf("\tSecond Integer:");
    while (scanf("%d", &j) != 1 || j <= 0) {
        while (getchar() != '\n'); // Clear input buffer
        printf("\n\tPlease enter a positive integer\n");
        printf("\n\tSecond Integer:");
    }
    if (rel_prime(i, j))
        printf("\n\tInteger %d and %d are relatively prime.\n", i, j);
    else
        printf("\n\tInteger %d and %d are NOT relatively prime.\n", i, j);
    printf("\n\tDo you want to try another number? \n\tType Y if yes and N if no:");
    while (getchar() != '\n'); // Clear input buffer
    ch = getchar();
} while (ch == 'Y' || ch == 'y');

    printf("\tThank you for using my program!");
    return 0;
}
