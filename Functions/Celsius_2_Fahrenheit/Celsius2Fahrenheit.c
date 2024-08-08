#include <stdio.h>

int main() 
{
    double celsius, fahrenheit;
 
    printf("Enter the temperature in degrees Celsius: ");
    scanf("%lf", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("%.2lf degrees Celsius is equivalent to %.2lf degrees Fahrenheit\n", celsius, fahrenheit);

    return 0;
}
