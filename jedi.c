#include <stdio.h>

int main()
{
    int height, age, citizenship, recommendation;
    printf("Are you a recommendee of Master Obi Wan? Type 1 if yes, type 0 if no: ");
    scanf("%d", &recommendation);


    if(recommendation == 0){
        printf("Type your age: ");
        scanf("%d", &age);
        if (age < 21 || age > 25)
            {printf("\nYou are not of age to be a Jedi.\n");
            goto L;}
        printf("Type your height: ");
        scanf("%d", &height);
        if (height < 200)
            {printf("\nYou are not tall enough to be a Jedi.\n");
             goto L;}
        printf("Are you a citizen of planet Endor? Type 1 if yes, type 0 if no: ");
        scanf("%d", &citizenship);
        if (citizenship != 1)
            {printf("\nYou are not a citizen of Planet Endor.\n");
             L:
                printf("\nAPPLICATION DENIED\n\n");}
        else
            printf("\nYOU ARE ACCEPTED. You have what it takes to be a Jedi.\n\n");
    }
    else if(recommendation == 1)
        printf("YOU ARE ACCEPTED. You have what it takes to be a Jedi.\n");
    else
        printf("\nInvalid input\n\n");

    return 0;
}
