/*
    This code snippet calculates the sum of a series composed of a sequence of terms obtained through fractions. By inputting an
    integer 'n' as a command-line argument, the program calculates the sum of the first 'n' terms in the series. After performing
    the calculations, the result of the series containing the 'n' terms is displayed as output. The underlying goal is to solve
    and display the series result for a specific value of 'n'.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    // Check if the number of command-line arguments is not equal to 2
    if (argc != 2) 
    {
        printf("Usage: %s <n>\n", argv[0]) ; // Indicates the correct usage of the program
        
        return 1 ; // Return an error code to signal the issue
    }

    int n = atoi(argv[1]) ; // Convert the command-line argument into an integer value
    double result = 0.0 ; // Initialize the variable to store the result of the series

    // Loop that iterates from 1 to n
    for (int i = 1; i <= n; i++) 
    {
        double term = 1.0 ; // Initialize the series term for the current iteration
        
        // Loop that iterates from 1 to i
        for (int j = 1; j <= i; j++) 
        {
            term *= (double) j / (j + 1) ; // Calculate the series term based on the iteration
        }

        result += term ; // Add the calculated term to the total result
    }

    // Print the result of the series with the number of terms n
    printf("Result of the series with n = %d: %.6f\n", n, result) ;

    return 0 ; // Return 0 to indicate successful program execution
}
