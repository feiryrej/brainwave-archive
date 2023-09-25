#include <stdio.h>
#include <stdlib.h>

void convert_to_12_hour_notation(int hour, int minute) {
    char* period = "AM"; // assume morning by default

    // convert to 12-hour notation
    if (hour == 0) {
        hour = 12;
    } else if (hour >= 12) {
        period = "PM";
        if (hour > 12) {
            hour -= 12;
        }
    }

    // print the time in 12-hour notation
    printf("\n\t\tRegular time is: %02d:%02d %s\n", hour, minute, period);
}

int main() {
    int time, hour, minute;
    char choice;
        printf("\n\t\tMilitary Time Converter!\n");
    do {
        printf("\tEnter a time in 24-hour notation (0-2400): ");
        while (scanf("%d", &time) != 1 || time < 0 || time > 2400) {
            printf("\n\n\tInvalid input");
            printf("\n\tplease enter a single integer between 0 and 2400\n");
            printf("\n\tInput Here:");
            while (getchar() != '\n'); // clear input buffer
        }

        hour = time / 100;
        minute = time % 100;

        convert_to_12_hour_notation(hour, minute);

        while (1) {
            printf("\n\tDo you want to try convert again? \n\tType Y if yes and N if no:");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
                break;
            }
            while (getchar() != '\n'); // clear input buffer
        }
    } while (choice == 'y' || choice == 'Y');
        printf("\tThank you for using my program!");

    return 0;
}
