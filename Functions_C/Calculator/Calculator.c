#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char operation, choice ;
    double num1, num2, result ;
    int continueCalculating = 1 ; // Initialize to 1 to enter the loop
    
    while (continueCalculating) 
    {
    	system("cls || clear") ; // Clear the screen for another calculation
    	
    	printf("==============================\n") ;
    	printf("Command Line Calculator\n");
    	printf("==============================\n") ;
    	
        printf("Available operations:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");

        printf("\nEnter the operation number: ");
        scanf(" %c", &operation);

        if (operation < '1' || operation > '4') 
        {
            printf("Error: Invalid operation number.\n");
            return 1; // Exit the program with an error code
        }

        printf("Enter the first number: ");
        scanf("%lf", &num1);

        printf("Enter the second number: ");
        scanf("%lf", &num2);

        switch (operation) 
        {
            case '1':
                result = num1 + num2;
                printf("Result --> %.2lf\n", result);
                break;
            case '2':
                result = num1 - num2;
                printf("Result --> %.2lf\n", result);
                break;
            case '3':
                result = num1 * num2;
                printf("Result --> %.2lf\n", result);
                break;
            case '4':
                if (num2 != 0) 
                {
                    result = num1 / num2;
                    printf("Result --> %.2lf\n", result);
                } 
                else 
                {
                    printf("Error: Division by zero is not allowed.\n");
                    return 1; // Exit the program with an error code
                }
                break;
            default:
                printf("Error: Invalid operator.\n");
                return 1; // Exit the program with an error code
        }

        printf("Do you want to perform another calculation? (Y/N): ");
        scanf(" %c", &choice);

        if (choice != 'Y' && choice != 'y') 
        {
            continueCalculating = 0; // Set to 0 to exit the loop
        }
    }

    return 0;
}
