#include <stdio.h>

#define MAX_SHOES 100 // sets the limit of the number of shoes 
#define NUM_SIZES 12 // based on the instruction, sizes are from 3-14
#define MIN_STYLE_NUMBER 0 // based on the instruction, style numbers are from 0-50
#define MAX_STYLE_NUMBER 50

// structure for shoe information: stock number, style number, number of pairs, and price
struct Shoe {
    int stockNumber;
    int styleNumber;
    int numPairs[NUM_SIZES];
    float price;
};

// functions for shoe inventory processes
int enterNewRecord(struct Shoe inventory[], int count, int * stockNumber); // function call at line , definition at lines
void displayRecord(const struct Shoe inventory[], int count); // function call at line , definition at lines
void changePrice(struct Shoe inventory[], int count); // function call at line , definition at lines
void changeStockOnHand(struct Shoe inventory[], int count); // function call at line , definition at lines

// main function
int main() {
    struct Shoe inventory[MAX_SHOES]; // structure variable inventory, which is an array with size MAX_SHOES (100), is declared
    int count = 0; // int variable count is declared and initialized to 0, used for tracking the number of shoes in the inventory to check if the inventory is already full
    int choice; // int variable choice is declared, used in user input for the process to operate

    int stockNumber = 0;

    // while loop continues as long as it is true
    while (1) {
        // program prompt for user navigation
        menu:
        printf("\n===========================================\n");
        printf("|     Shoe Store Inventory Management     |\n"); // program introductory title
        printf("===========================================\n");
        printf("|                                         |\n");
        printf("|                Options:                 |\n");
        printf("|                                         |\n");
        printf("|  [1] Enter a new record                 |\n"); // shows first process: entering a new record
        printf("|  [2] Display a record                   |\n"); // shows second process: displaying an existing record
        printf("|  [3] Change the price of a stock item   |\n"); // shows third process: changing price of a stock item
        printf("|  [4] Change the number on hand          |\n"); // shows fourth process: changing the number of on hand 
        printf("|  [5] Exit                               |\n"); // shows exit option
        printf("|                                         |\n");
        printf("===========================================\n");

        //  gets user input for chosen inventory process 
        printf("\n Please enter your choice (1-5): ");
        while (scanf("%d", & choice) != 1 || choice > 5 || choice < 1) { // checks if user input is valid (int, between 1-5)
            printf("\n Invalid input. Please enter numbers from 1-5 only!\n"); // displays invalid input to the user
            while (getchar() != '\n'); // clears invalid input in the input buffer until it encounters a newline
            printf("\n Please enter your choice (1-5): "); // asks the user to enter another input
        };

        // assesses the user input and operates depending on the value of variable choice 
        switch (choice) {
        case 1:
            count = enterNewRecord(inventory, count, & stockNumber); // calls enterNewRecord function and stores the return value to count
            break;
        case 2:
            displayRecord(inventory, count); // calls displayRecord function
            break;
        case 3:
            changePrice(inventory, count); // calls changePrice function
            break;
        case 4:
            changeStockOnHand(inventory, count); // calls changeStockOnHand
            break;
        case 5: {
            char exit_choice;  // creates a character variable choice to serve as storage for the users answer
            exit:
            	printf(" Do you really want to exit the program?\n [Y] Yes\n [N] No\n Choice: ");
                while (getchar() != '\n');  // clear previous buffers in the input buffer
                
                while (scanf("%c", &exit_choice) != 1) { // checks if user input is valid (character, lower or uppercase Y or N)
                    printf("\n Invalid input. You may only enter the characters Y or N!\n"); // displays invalid input to the user
                    while (getchar() != '\n'); // clears invalid input in the input buffer until it encounters a newline
                    printf(" Do you really want to exit the program?\n [Y] Yes\n [N] No\n Choice: ");
                };
            	
            	if(exit_choice == 'N' || exit_choice == 'n') goto menu;  // if they answered no, the program will go to the keyword 'menu'
            	else if(exit_choice== 'Y' || exit_choice == 'y') {  // if they answered yes, then the program will exit 
                  	printf("\n Thank you for using the Shoe Store Inventory Management system!\n"); // serves as the program exit
                  	return 0;
                }
            	else if(exit_choice!= 'Y' && exit_choice != 'y' && exit_choice != 'N' && exit_choice != 'n') { 
                  	printf(" Invalid input. Enter y/n keys only.\n");
                  	goto exit;
                }
           		return 0;
   	 	}
        default:
            printf("\n Invalid choice! Please try again.\n"); // displays invalid input, prompting the user to enter another output
        }
    }
}

// function that allows the user to enter a new shoe record
// accepts the structure variable inventory (array), int variable count, and int pointer variable stockNumber as parameters
int enterNewRecord(struct Shoe inventory[], int count, int * stockNumber) {
    // checks if the current number of shoes (count) already reached the limit MAX_SHOES (100) 
    if (count == MAX_SHOES) {
        printf("\n\nInventory is full. Cannot add more records.\n"); // prompts user that inventory is already full
        return count; // count value is returned to main
    }

    int input = 0; // int variable input is declared and initialized to 0

    // while loop continues as long as it is true
    while (1) {
        // program prompt for user navigation
        printf("\n\n===========================================\n");
        printf("|     Shoe Store Inventory Management     |\n");
        printf("===========================================\n");
        printf("|                                         |\n");
        printf("|           Enter a new record            |\n");
        printf("|                                         |\n");
        printf("|=========================================|\n\n");

        inventory[count].stockNumber = * stockNumber; // assigns value of stockNumber to field stockNumber of structure variable inventory (array)
        printf(" Stock Number: %d\n", inventory[count].stockNumber); // displays the stockNumber

        style_number_input:
            printf(" Style Number (0-50): ");
        while (scanf("%d", & input) != 1 || input < MIN_STYLE_NUMBER || input > MAX_STYLE_NUMBER) { // checks if user input is valid (int, between min_style_number (0) and max_style_number (50))
            printf(" Invalid input. Please enter a style number between %d and %d.\n", MIN_STYLE_NUMBER, MAX_STYLE_NUMBER);
            while (getchar() != '\n');
            printf(" Style Number (0-50): ");
        }

        // accesses the values of array of structures (inventory)
        for (int i = 0; i <= count; i++) {
            if (input == inventory[i].styleNumber) {// checks if the field styleNumber of that array element of index i is equal to input
                printf("\n The given style number has already been assigned to shoe stock #%i. Please enter a number between %d and %d.\n\n", inventory[i].stockNumber, MIN_STYLE_NUMBER, MAX_STYLE_NUMBER);
                goto style_number_input; // goes back to style_number_input tag
            }
        }

        inventory[count].styleNumber = input; // assigns the value of input to field styleNumber of the same array element of index i

        printf(" Number of pairs in each size (Size 3-14)\n"); // displays the prompt number of pairs in each size
        printf("\n");
        for (int i = 0; i < NUM_SIZES; i++) {
            printf(" *Size %d: ", i + 3);
            int numPairs; // declares int variable numPairs for storing number of shoe pairs
            while (scanf("%d", & numPairs) != 1 || numPairs < 0 || numPairs > 999) {// checks if user input is valid (int, between 0 to 999)
                printf(" Invalid input. Please enter integers between 0 and 999 only!\n"); // displays invalid input to the user
                while (getchar() != '\n'); // clears invalid input in the input buffer until it encounters a newline
                printf(" *Size %d: ", i + 3); // asks the user to enter another input
            }
            inventory[count].numPairs[i] = numPairs; // assigns numPairs value to numPairs field (array) of that array element of index count
        }

        printf("\n Price: $");
        while (scanf("%f", & (inventory[count].price)) != 1 || inventory[count].price < 0 || getchar() != '\n') {// checks if user input is valid (float, positive number)
            printf(" Invalid input. Please enter non-negative numbers only!\n"); // displays invalid input to the user
            while (getchar() != '\n'); // clears invalid input in the input buffer until it encounters a newline
            printf("\n Price: $"); // asks the user to enter another input
        };

        printf("\n\n");

        count++; // increments count to update the number of shoes in the inventory
        (*stockNumber)++; // increments stockNumber 

        // displays prompt for user navigation to either repeat the process or return to main menu
        printf("===========================================\n\n");
        printf(" [1] Enter another record\n");
        printf(" [2] Back to main menu\n");
        printf("\n===========================================\n");

        int choice; // declares int variable choice
        printf("\n Please enter your choice (1-2): ");
        while (scanf("%d", & choice) != 1 || choice < 1 || choice > 2) {// checks if user input is valid (int, between 1-2)
            printf(" Invalid input. Please enter 1 or 2 only!\n"); // displays invalid input to the user
            while (getchar() != '\n'); // clears invalid input in the input buffer until it encounters a newline
            printf("\n Please enter your choice (1-2): "); // displays invalid input to the user
        }

        if (choice == 2) {// checks if choice is equal to 2 (return to main menu)
            break; // loop breaks
        }
    }

    return count; // count value is returned to main
}

// function that allows the user to display a shoe record
void displayRecord(const struct Shoe inventory[], int count) {
    while (1) { // allows the user to perform multiple stock changes until they choose to exit
        // header for the display record menu
        printf("\n\n===========================================\n");
        printf("|     Shoe Store Inventory Management     |\n");
        printf("===========================================\n");
        printf("|                                         |\n");
        printf("|           Display a record              |\n");
        printf("|                                         |\n");
        printf("|=========================================|\n\n");

        printf(" [1] Search by Stock Number\n");
        printf(" [2] Search by Style Number\n");

        // prompts the user for their choice and performs input validation to ensure they enter a valid choice (1 or 2)
        int choice;
        printf("\n Please enter your choice (1-2): ");
        while (scanf("%d", & choice) != 1 || choice > 2 || choice < 1) {
            printf("\nInvalid input. Please enter numbers from 1-2 only!\n");
            while (getchar() != '\n');
            printf("\nPlease enter your choice (1-2): ");
        }

        int number; // stores the stock number or style number entered by the user
        int found = 0; // variable to track if a matching record is found

        switch (choice) {
        case 1: // when the user chooses to search by stock number, it asks the user to enter a stock number and performs input validation
            printf(" Enter Stock Number: ");
            while (scanf("%d", & number) != 1) {
                printf(" Invalid input. Please enter integers only!\n");
                while (getchar() != '\n');
                printf(" Enter Stock Number: ");
            }

            // This loop iterates over the inventory to find a matching stock number. If a match is found, the found is set to 1.
            for (int i = 0; i < count; i++) {
                if (inventory[i].stockNumber == number) {
                    found = 1;
                    printf("\n===========================================\n");
                    printf("\n RECORD FOUND\n\n");
                    printf(" Stock Number: %d\n", inventory[i].stockNumber);
                    printf(" Style Number: %d\n", inventory[i].styleNumber);
                    printf(" Number of pairs in each size:\n\n");

                    for (int j = 0; j < NUM_SIZES; j++) {
                        printf(" *Size %d: %d\n", j + 3, inventory[i].numPairs[j]);
                    }

                    printf("\n Price: $%.2f\n", inventory[i].price);
                    printf("\n===========================================\n");
                    break;
                }
            }
            break;

        case 2: // when the user chooses to search by style number, it asks the user to enter a style number and performs input validation
            printf(" Enter Style Number: ");
            while (scanf("%d", & number) != 1) {
                printf(" Invalid input. Please enter integers only!\n");
                while (getchar() != '\n');
                printf(" Enter Style Number: ");
            }

            // This loop iterates over the inventory to find a matching style number. If a match is found, the found is set to 1.
            for (int i = 0; i < count; i++) {
                if (inventory[i].styleNumber == number) {
                    found = 1;
                    printf("\n===========================================\n");
                    printf("\n RECORD FOUND\n\n");
                    printf(" Stock Number: %d\n", inventory[i].stockNumber);
                    printf(" Style Number: %d\n", inventory[i].styleNumber);
                    printf(" Number of pairs in each size:\n\n");

                    for (int j = 0; j < NUM_SIZES; j++) {
                        printf(" *Size %d: %d\n", j + 3, inventory[i].numPairs[j]);
                    }

                    printf("\n Price: $%.2f\n", inventory[i].price);
                    printf("\n===========================================\n");
                    printf("\n\n");
                    break;
                }
            }
            break;

        default: // executed when the user enters an invalid choice (neither 1 nor 2)
            printf(" Invalid choice!\n");
        }

        // If no matching stock or style number is found in the inventory
        if (!found) {
            printf("\n===========================================\n");
            printf("\n Record not found!\n");
            printf("\n===========================================\n");
        }

        printf("\n [1] Display another record\n");
        printf(" [2] Back to main menu\n");

        // user is prompted to enter their choice and input validation is performed to ensure a valid choice is entered
        int displayChoice;
        printf("\nPlease enter your choice (1-2): ");
        while (scanf("%d", & displayChoice) != 1 || displayChoice < 1 || displayChoice > 2) {
            printf(" Invalid input. Please enter 1 or 2 only!\n");
            while (getchar() != '\n');
            printf("\n Please enter your choice (1-2): ");
        }

        if (displayChoice == 2) { // If the user chooses to go back to the main menu, the loop is exited
            break;
        }
    }
}

// function that allows the user to change the price of a shoe record
void changePrice(struct Shoe inventory[], int count) {
    while (1) { // allows the user to perform multiple stock changes until they choose to exit
        // header for the price change menu
        printf("\n\n===========================================\n");
        printf("|     Shoe Store Inventory Management     |\n");
        printf("===========================================\n");
        printf("|                                         |\n");
        printf("|            Change a price               |\n");
        printf("|           For a Stock Item              |\n");
        printf("|                                         |\n");
        printf("|=========================================|\n\n");

        printf(" [1] Search by Stock Number\n");
        printf(" [2] Search by Style Number\n");

        // prompts the user for their choice and performs input validation to ensure they enter a valid choice (1 or 2)
        int choice;
        printf("\n Please enter your choice (1-2): ");
        while (scanf("%d", & choice) != 1 || choice > 2 || choice < 1) {
            printf("\n Invalid input. Please enter numbers from 1-2 only!\n");
            while (getchar() != '\n');
            printf("\n Please enter your choice (1-2): ");
        }

        int number; // stores the stock number or style number entered by the user
        int found = 0; // variable to track if a matching record is found

        switch (choice) {
        case 1: // when the user chooses to search by stock number, it asks the user to enter a stock number and performs input validation
            printf(" Enter Stock Number: ");
            while (scanf("%d", & number) != 1) {
                printf(" Invalid input. Please enter integers only!\n");
                while (getchar() != '\n');
                printf(" Enter Stock Number: ");
            }

            // This loop iterates over the inventory to find a matching stock number. If a match is found, the found is set to 1.
            for (int i = 0; i < count; i++) {
                if (inventory[i].stockNumber == number) {
                    found = 1;
                    printf("\n===========================================");
                    printf("\n\n Current Price: $%.2f\n", inventory[i].price); // displays the current price
                    printf(" Enter New Price: $"); // prompts the user for a new price
                    while (scanf("%f", & (inventory[i].price)) != 1) { // performs input validation
                        printf(" Invalid input. Please enter a valid price!\n");
                        while (getchar() != '\n');
                        printf(" Enter New Price: $");
                    }
                    printf("\n===========================================\n");
                    printf("\n Price updated successfully!\n\n");
                    break;
                }
            }
            break;

        case 2: // when the user chooses to search by style number, it asks the user to enter a style number and performs input validation
            printf(" Enter Style Number: ");
            while (scanf("%d", & number) != 1) {
                printf(" Invalid input. Please enter integers only!\n");
                while (getchar() != '\n');
                printf(" Enter Style Number: ");
            }

            // This loop iterates over the inventory to find a matching style number. If a match is found, the found is set to 1.
            for (int i = 0; i < count; i++) {
                if (inventory[i].styleNumber == number) {
                    found = 1;
                    printf("\n===========================================\n");
                    printf("\n\n Current Price: $%.2f\n", inventory[i].price); // displays the current price
                    printf(" Enter New Price: $"); // prompts the user for a new price
                    while (scanf("%f", & (inventory[i].price)) != 1) { // performs input validation
                        printf(" Invalid input. Please enter a valid price!\n");
                        while (getchar() != '\n');
                        printf(" Enter New Price: $");
                    }
                    printf("\n===========================================\n");
                    printf("\n\n Price updated successfully!\n\n");
                    break;
                }
            }
            break;

        default: // executed when the user enters an invalid choice (neither 1 nor 2)
            printf(" Invalid choice!\n");
        }

        // If no matching stock or style number is found in the inventory
        if (!found) {
            printf("\n===========================================\n");
            printf("\n Record not found!\n");
            printf("\n===========================================\n\n");
        }

        printf(" [1] Change the price for another record\n");
        printf(" [2] Back to main menu\n");

        // user is prompted to enter their choice and input validation is performed to ensure a valid choice is entered
        int changeChoice;
        printf("\n Please enter your choice (1-2): ");
        while (scanf("%d", & changeChoice) != 1 || changeChoice < 1 || changeChoice > 2) {
            printf(" Invalid input. Please enter 1 or 2 only!\n");
            while (getchar() != '\n');
            printf("\n Please enter your choice (1-2): ");
        }

        if (changeChoice == 2) { // If the user chooses to go back to the main menu, the loop is exited
            break;
        }
    }
}

// function allows the user to change the number of stock on hand of a shoe record
void changeStockOnHand(struct Shoe inventory[], int count) {
    while (1) { // allows the user to perform multiple stock changes until they choose to exit
        // header for the stock change menu
        printf("\n\n===========================================\n");
        printf("|     Shoe Store Inventory Management     |\n");
        printf("===========================================\n");
        printf("|                                         |\n");
        printf("|            Change the number            |\n");
        printf("|                 on hand                 |\n");
        printf("|                                         |\n");
        printf("|=========================================|\n\n");

        // display options for searching the inventory by stock number or style number
        printf(" [1] Search by Stock Number\n");
        printf(" [2] Search by Style Number\n");

        // prompts the user for their choice and performs input validation to ensure they enter a valid choice (1 or 2)
        int choice;
        printf("\n Please enter your choice (1-2): ");
        while (scanf("%d", & choice) != 1 || choice > 2 || choice < 1) {
            printf("\n Invalid input. Please enter numbers from 1-2 only!\n");
            while (getchar() != '\n');
            printf("\n Please enter your choice (1-2): ");
        }

        int number; // stores the stock number or style number entered by the user
        int found = 0; // variable to track if a matching record is found

        switch (choice) {
        case 1: // when the user chooses to search by stock number, it asks the user to enter a stock number and performs input validation
            printf(" Enter Stock Number: ");
            while (scanf("%d", & number) != 1) {
                printf(" Invalid input. Please enter integers only!\n");
                while (getchar() != '\n');
                printf(" Enter Stock Number: ");
            }

            // This loop iterates over the inventory to find a matching stock number. If a match is found, the found is set to 1.
            for (int i = 0; i < count; i++) {
                if (inventory[i].stockNumber == number) {
                    found = 1;

                    same_stock_one:
                        printf("\n===========================================\n");
                    printf("\n Current Stock on Hand\n\n");

                    // displays the current stock on hand for each shoe size
                    for (int j = 0; j < NUM_SIZES; j++) {
                        printf(" *Size %d: %d\n", j + 3, inventory[i].numPairs[j]);
                    }
                    printf("\n===========================================\n");

                    /* prompts the user to enter the shoe size they want to change the stock on hand for 
                     and performs input validation to ensure a valid size is entered*/
                    printf("\n Enter the size to change the stock on hand: ");
                    int size;
                    while (scanf("%d", & size) != 1 || size < 3 || size > 14) {
                        printf("\n Invalid Input. Please enter size 3 to 14 only!");
                        while (getchar() != '\n');
                        printf("\n Enter the size to change the stock on hand: ");
                    };

                    /* It allows the user to enter the new quantity for a specific shoe 
                      size and updates the inventory accordingly*/
                    if (size >= 3 && size <= 14) {
                        printf(" Enter the new quantity for Size %d: ", size);
                        int newQuantity;
                        scanf("%d", & newQuantity);

                        inventory[i].numPairs[size - 3] = newQuantity;
                        printf("\n====================================================\n");
                        printf("\n Stock on hand for Size %d updated successfully!\n", size);
                        printf("\n====================================================\n");
                        printf("\n");
                    } else { // If the entered size is not within the valid range (3 to 16), an error message is displayed
                        printf(" Invalid size! Size must be between 3 and 16.\n");
                    }

                    break;
                }
            }
            break;

        case 2: // when the user chooses to search by style number, it asks the user to enter a style number and performs input validation
            printf(" Enter Style Number: ");
            while (scanf("%d", & number) != 1) {
                printf(" Invalid input. Please enter integers only!\n");
                while (getchar() != '\n');
                printf(" Enter Style Number: ");
            }

            // This loop iterates over the inventory to find a matching style number. If a match is found, the found is set to 1.
            for (int i = 0; i < count; i++) {
                if (inventory[i].styleNumber == number) {
                    found = 1;

                    same_stock_two:
                        printf("\n===========================================\n");
                    printf("\n Current Stock on Hand\n\n");

                    // displays the current stock on hand for each shoe size
                    for (int j = 0; j < NUM_SIZES; j++) {
                        printf(" *Size %d: %d\n", j + 3, inventory[i].numPairs[j]);
                    }
                    printf("\n===========================================\n");

                    /* prompts the user to enter the shoe size they want to change the stock on hand for 
                     and performs input validation to ensure a valid size is entered*/
                    printf("\n Enter the size to change the stock on hand: ");
                    int size;
                    while (scanf("%d", & size) != 1 || size < 3 || size > 14) {
                        printf("\n Invalid Input. Please enter size 3 to 14 only!");
                        while (getchar() != '\n');
                        printf("\n Enter the size to change the stock on hand: ");
                    };

                    if (size >= 3 && size <= 14) {
                        printf(" Enter the new quantity for Size %d: ", size);
                        int newQuantity;
                        scanf("%d", & newQuantity);

                        inventory[i].numPairs[size - 3] = newQuantity;
                        printf("\n====================================================\n");
                        printf("\n Stock on hand for Size %d updated successfully!\n", size);
                        printf("\n====================================================\n");
                        printf("\n");
                    } else {
                        printf(" Invalid size! Size must be between 3 and 14.\n");
                    }
                    break;
                }
            }
            break;

        default: // executed when the user enters an invalid choice (neither 1 nor 2)
            printf("Invalid choice!\n");
        }

        // If no matching stock or style number is found in the inventory
        if (!found) {
            printf("\n===========================================\n");
            printf("\n Record not found!\n");
            printf("\n===========================================\n\n");
        }

        printf(" [1] Change the number on hand of the same stock\n");
        printf(" [2] Change the number on hand of a different stock\n");
        printf(" [3] Back to the main menu\n");

        // user is prompted to enter their choice and input validation is performed to ensure a valid choice is entered
        int changeChoice;
        printf("\n Please enter your choice (1-3): ");
        while (scanf("%d", & changeChoice) != 1 || changeChoice < 1 || changeChoice > 3) {
            printf(" Invalid input. Please enter 1 or 3 only!\n");
            while (getchar() != '\n');
            printf("\n Please enter your choice (1-3): ");
        }

        if (changeChoice == 3) {
            return; // the program returns back to the main menu
        } else if (changeChoice == 1) {
            if (found == 0) { // If the user chooses to change the number on hand of the same stock and no stock has been found
                printf("\n The program can't change the number of stock on hand as you have not entered a valid stock yet.\n");
                continue;
            } else if (choice == 1) // If a stock is found, the program jumps back to the appropriate label
                goto same_stock_one; // to allow the user to make additional changes for the same stock
            else if (choice == 2)
                goto same_stock_two;
        }
    }
}