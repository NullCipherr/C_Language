/*
    The purpose of the code is to find and display pairs of amicable numbers in the range from 1 to N, where N is the input number.
    The sumDivisors function is used to calculate the sum of proper divisors of a number. The outer loop iterates through all numbers from 1 to N,
    while the inner loop checks if the current number forms an amicable pair with another number within the range. If an amicable pair is found,
    it is printed to the output. The problem explores the mathematical property of amicable numbers, where the sum of proper divisors of one number
    equals the other number in the pair, and vice versa.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of proper divisors of a number
int sumDivisors(int num) 
{
    // Start with 1 to include the divisor 1
    int sum = 1 ; 
    
    // Iterate through potential divisors up to the square root of num
    for (int i = 2; i * i <= num; ++i) 
    { 
        // Check if i is a divisor of num
        if (num % i == 0) 
        { 
            sum += i ; // Add i to the sum of proper divisors

            // If i is not the square root of num, avoid counting duplicate divisors
            if (i != num / i) 
            {
                sum += num / i ; // Add num/i to the sum of proper divisors
            }
        }
    }
    return sum ; // Return the sum of proper divisors
}

int main(int argc, char *argv[]) 
{
    int n = atoi(argv[1]) ;

    // Print the header for the output
    printf("Amicable number pairs up to %d:\n", n) ;

    // Loop to check amicable number pairs
    for (int numA = 1; numA <= n; ++numA) 
    {
        int sumA = sumDivisors(numA) ; // Calculate the sum of proper divisors of numA
        
        // Check if the sum is greater than numA and within the limit N
        if (sumA > numA && sumA <= n) 
        { 
            int sumB = sumDivisors(sumA) ; // Calculate the sum of proper divisors of sumA
            
            // Check if the sum of proper divisors of sumA is equal to numA
            if (sumB == numA) 
            { 
                printf("(%d, %d)\n", numA, sumA) ; // Print the pair of amicable numbers
            }
        }
    }

    return 0 ;
}
