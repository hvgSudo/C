/* Program to print sine function
   for an input x between (0,1)
   
   Harsh Vardhan Guleria

   13-05-2020
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    float input;
    printf("Enter x: ");
    scanf("%f", &input);
    printf("\nThe sine value of %f radians = %f\n", input, sin(input));
    printf("\nThe sine value of %f degrees = %f\n", input, sin(input * (3.14159 / 180)));
    return 0;
}