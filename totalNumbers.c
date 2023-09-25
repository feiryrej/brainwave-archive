#include <stdio.h>
int main(){
    int n1, n2, m, loop;
    int a=0;
    char ch;

    do
{
    printf("Please input the smaller number: ");
    scanf("%d", &n1);
    printf("Please input the larger number: ");
    scanf("%d", &n2);
    printf("Please input the divisor: ");
    scanf("%d", &m);

    while (n1%m != 0 && n1<=n2)
    {
        n1++;
    }
    for(int i=1; n1<=n2; i++)
        {
            printf("%d ", n1);
            n1=n1+m;
            a=i;
        }
        printf("\nThere are a total of %d numbers\n\n", a);

        printf("Do you want to try again? Press Y if yes, Press N if no:");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
        printf("Thank you!");
return 0;

}
