#include <stdio.h>

// Function to check if a number is prime or not
int prime(int n) {
  int i;
  char ch;
  // Check if number is nonnegative
  if (n <= 0)
    return 0;

  // Check if number is divisible by any number from 2 to itself
  for (i = 2; i <= n/2; i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main(){
  int num;
  char ch;

 do {
    printf("\n\tPrime Numbers Calculator\t");
    printf("\n\tEnter a non-negative integer: ");
    while (scanf("%d", &num) != 1 || num < 0) {
      printf("\n\tInvalid number.\n");
      while (getchar() != '\n');
      printf("\n\tDo you want to try again? \n\tType Y if yes and N if no:");
      scanf(" %c", &ch);

      if (ch == 'N' || ch == 'n')
        break;

      printf("\n\tEnter a non-negative integer: ");
    }
    if (ch == 'N' || ch == 'n')
      break;

    if (num == 0)
      printf("\n\n\tInvalid Number");
    else if (prime(num))
      printf("\n\n\t%d is a prime number.\n", num);
    else
      printf("\n\n\t%d is NOT a prime number.\n\tIt is a composite number.\n", num);

    printf("\n\n\tDo you want to try another number? \n\tType Y if yes and N if no:");
    scanf(" %c", &ch);

  } while (ch == 'Y' || ch == 'y');

  printf("\n\n\tThank you for using my program!");

  return 0;
}

