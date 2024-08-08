#include <stdio.h>

int main() 
{
    int n;
    long long factorial = 1;
    char choice;

    while (1) 
    { // Infinite loop
        printf("\nEnter a non-negative integer (or press 'Q' to quit): ") ;
        scanf(" %c", &choice);

        if (choice == 'Q' || choice == 'q') 
        {
            break; // Exit the loop if 'Q' or 'q' is pressed
        }

        sscanf(&choice, "%d", &n);

        if (n < 0) 
        {
            printf("Error: Please enter a non-negative integer.\n");
            continue; // Skip the current iteration and continue the loop
        }

        factorial = 1;

        for (int i = 1; i <= n; i++) 
        {
            factorial *= i;

            // Check for overflow
            if (factorial < 0) 
            {
                printf("Error: Overflow occurred. The result is too large to compute.\n");
                break; // Exit the loop if overflow occurs
            }
        }

        if (factorial >= 0) 
        {
            printf("The factorial of %d is %lld\n", n, factorial);
        }
    }

    return 0;
}
