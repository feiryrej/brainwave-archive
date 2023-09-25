#include <stdio.h>
void DWARF(int number)
{
    int sum = 0;
    int input = number;
    printf("Factors are: ");
    for(int i = 1; i <= input; i++)
    {
        if(input % i == 0)
        {
            printf("%i ", i);
            input /= i;
        }
    }

    input = number;
    printf("\nSum of its factor: ");
    for(int i = 1; i <= input; i++)
    {
        if(input % i == 0)
        {
            printf("%i", i);
            sum += i;
            input /= i;

            if(i < input)
            {
                printf(" + ");
            }
        }
    }
    printf(" = %i\n", sum);
    float half = number / 2.0;
    printf("Half of the number: %i / 2 = %.1f\n", number, half);
    if (sum > half)
        printf("%i is DWARF\n", number);
    else
        printf("%i is NOT DWARF\n", number);
}

int main(void)
{
    int number;
    printf("Input number: ");
    if (scanf("%i", &number) == 0 || number <= 0)
    {
        printf("Invalid input. The program only accepts non-negative integers.\n");
        return 1;
    }
    DWARF(number);
    return 0;
}
