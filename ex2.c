/******************
Name: Alon Cohen
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main()
{
    // MAIN MENU LOOP
    while (1) {
        int choice;
        while (1) {
            printf("\n");
            printf("Welcome to our games, please choose an option:\n");
            printf("1. Ducky's Unity Game\n");
            printf("2. The Memory Game\n");
            printf("3. Professor Pat's Power Calculation\n");
            printf("4. The Duck Parade\n");
            printf("5. The Mystery of the Repeated Digits\n");
            printf("6. Good Night Ducks\n");
            
            scanf("%d", &choice);
            if (choice > 0 && choice < 7)
                break;      
            else
                printf("Invalid number, please select a number between 1 and 6\n");
        }
        if (choice == 1) {
        // TASK 1: Ducky's Unity Game
        // Gets user number and breaks once the user enter a positive number
            int n;
            while (1) {
                printf("please enter a positive number:\n");
                scanf("%d", &n);
                if (n > 0)
                    break;
                else
                    printf("Invalid number, please try again\n");
            }
            int counter = 0;
            for (int i=0; i<=31; i++) {
                counter += (n >>i) & 1;
            }
            printf ("Ducky earns %d corns\n", counter);
        }
        else if (choice == 2) {
            // TASK 2: The Memory Game
            int n;
            while (1) {
                printf("please enter the number of ducks:\n");
                scanf("%d", &n);
                if (n < 0 || n > 63)
                    printf("Invalid number, please try again\n");
                else {
                    printf("you entered %d ducks\n", n);
                    break;
                }
                    
                
            }
            int long long QUAK = 0;
            // Loop through all of the ducks and change their index's bit on QUAK to 1 if they Quaked
            for (int i=0;i<n;i++) {
                int q;
                while (1) {
                    printf("duck %d do QUAK? 1 for yes, 0 for no\n", i+1);
                    scanf("%d", &q);
                    if (q==0 || q==1)
                        break;
                    else
                        printf("Invalid number, you can only type 1 for yes, 0 for no!\n");
                }
                if (q)
                    QUAK = QUAK ^ (1 << i);
                }
                
            for (int i=0;i<n;i++) {
                if ((QUAK >> i) & 1)
                    printf("duck number %d do Quak\n", i+1);
                else
                    printf("duck number %d do Sh...\n", i+1);
                }     
        }
        
        // TASK 3: Professor Pat's Power Calculation
        else if (choice == 3) {
            int num;
            int exponent;
            int result = 1;
            while (1) {
                printf("please enter the number\n");
                scanf("%d", &num);
                
                printf("please enter the exponent\n");
                scanf("%d", &exponent);
                
                if (num < 0 || exponent < 0)
                    printf("Invalid number, please try again. Both numbers can't be negative!\n");
                else
                    break;

            }
            // If num is 0 - the result of the power is 0
            if (num == 0)
                printf("your power is: %d\n", 0);
            
            // // If exponent is 0 - the result of the power is 1
            else if (exponent == 0)
                printf("your power is: %d\n", 1);
            
            else {
                for (int i=1;i<=exponent;i++)
                    result *= num;
                printf("your power is: %d\n", result);
            }   
        }
        
        // TASK 4: The Duck Parade
        else if (choice == 4) {
            int ducks;
            while (1) {
                printf("please enter number of ducks:\n");
                scanf("%d", &ducks);
                if (ducks > 0)
                    break;
                else
                    printf("Invalid number, please try again\n");
            }
            while (ducks > 0) {
                int row_ducks = (ducks > 9) ? 10 : ducks;
                
                for (int i=row_ducks; i>0; i--) 
                    printf("   _\t\t");
                
                printf("\n");
                
                for (int j=row_ducks; j>0; j--) 
                    printf("__(o)>\t\t");
                
                printf("\n");
                
                for (int w=row_ducks; w>0; w--) 
                    printf("\\___)\t\t");
                
                if (row_ducks==10)
                    printf("\n");
        
                ducks = ducks-row_ducks;
                    
            }
            printf("\n");
        }
        
        // TASK 5: The Mystery of the Repeated Digits
        else if (choice == 5) {
            int num;
            while (1) {
                printf("please enter number\n");
                scanf("%d", &num);
                if (num > 0)
                    break;
                else
                    printf("Invalid number, please try again\n");
            }
            // Sets the corresponding bit from the left. If that bit is already set, the number has appeared before.
            int checker = 0;
            while (num > 0) {
                int right_digit = num % 10;
                if ((checker >> right_digit) & 1)
                    printf("%d appears more than once!\n", right_digit);
                else 
                    checker = checker ^ (1 << right_digit);
                num = num /10;
            }
        }
        // TASK 6: EXIT
        else if (choice == 6) {
            printf("Good night! See you at the pond tomorrow.\n");
            break;
        }
            
        
        
    }
    return 0;
}
