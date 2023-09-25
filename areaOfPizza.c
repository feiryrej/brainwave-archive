#include <stdio.h>

int main (int argc, const char * argv[])
{
    int size, price, radius, loop;
    float area, per_square;
    char ch;

    do{
    printf("Please enter the diameter or size (10 inches, 12 inches and 14 inches) :");
    scanf("%d", &size);
    printf("Please enter the price of your chosen pizza (10 inches-178 pesos, 12 inches-259 pesos, 14 inches-314 pesos):");
    scanf("%d", &price);

    radius=size/2;
    area =3.1415926 * (radius) * (radius);
    per_square=price/area;

    printf("\nArea of the pizza: %0.2f square inches.\n", area);
    printf("Orice of the pizza per square inch: %0.2f pesos.\n", per_square);
    printf("\nDo you want to check other pizza? Press Y if yes, Press N if no:");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
        printf("Thank you!");
    return 0;
}
