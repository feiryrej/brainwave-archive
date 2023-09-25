#include <stdio.h>
int main(){
     int n, i = 2, factor, c, loop;
    do
    {
    printf("Please input a non-negative integer: ");
    if (scanf("%d", &n) == 0)
    {
     printf("INVALID INPUT\n");
     return 0;
    } while(n<=0);

    printf("The prime factors of %d are: ", n);
    printf("1 ");
     while(i <= n)
    {
        factor = 0;
        while(n % i == 0)
        {
            factor++;
            n /= i;
        }
        if(factor > 0)
        {
            printf("%d ", i);
        }
        i++;
    }
    printf("\nDo you want to try another number? Input 1 if yes, Input 2 if not: ");
    scanf("%d", &loop);
    }while(loop==1);
        printf("Thank you for using our service!");

    return 0;
}
