#include <stdio.h>
int main (){
    int type, late, fine, loop;
    char ch;

    do{
    printf("Did you rent a CD or a VHS? Type 1 for CD, Type 2 for VHS:");
    scanf("%d", &type);
    printf("Number of days you are late: ");
    scanf("%d", &late);
    if (late<=2)
        fine = 10;
    else if (late <=4 && late>2)
        fine = 15;
    else if (late==5)
        fine = 20;
    else if (late==6)
        fine = 25;
    else if (late>=7){
        if (type==1)
        fine=50;
        else if (type==2)
        fine=35;
    }
    printf("The fine will be %d pesos:\n", fine);
    printf("Did you rent other stuff? Press Y if yes, Press N if no: ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
        printf("Thank you!");
return 0;
}
