#include<stdio.h>
#include<math.h>

#define START 700
#define FINISH 1100

int main()
{
    int i, j;
    printf("Every even number greater than 2 is the sum of two primes:\n\n");
    for(i = START; i <= FINISH; i++)
    {
        if(i % 2 == 0)
        {
            for(j = 2; j <= i/2; j++)
            {
                if(isPrime(j) && isPrime(i-j))
                {
                    printf("%d = %d + %d\n", i, j, i-j);
                    break;
                }
            }
        }
    }
    return 0;
}

int isPrime(int n)
{
    int i;
    for(i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
