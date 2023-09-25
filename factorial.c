#include <stdio.h>

int main(){
    int num, start = 1, factorial = 1, base;

    do
    {
        base = 0;
        printf("Please enter a non-negative integer: ");
        scanf("%i", &num);

    }
    while(num < base);

    do
    {
        printf("%d\t", start);
        factorial = factorial * start;
        start++;
    }
    while(start <= num);

    printf("\n\nThe factorial of %d is %d.\n", num, factorial);
    return 0;
}
