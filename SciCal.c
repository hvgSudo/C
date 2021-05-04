#include <stdio.h>
#include <math.h>
#define PI 3.141592
int main()
{
    int f, s, i, t = 1, o = 1;
    char a;
    float fn, sn;
    printf("\n\t ------------ Briefing ------------\n");
    printf("\n\t Enter one of the operations given below");
    printf("\n\t Enter the first number and then the second number");
    printf("\n\t +        for addition");
    printf("\n\t -        for subtraction");
    printf("\n\t *        for multiplication");
    printf("\n\t /        for division");
    printf("\n\t #        for remainder");
    printf("\n\t !        for factorial");
    printf("\n\t r        for square root");
    printf("\n\t ^        for power of any number");
    printf("\n\t l        for logarithm to the base 10");
    printf("\n\t n        for natural logarithm");
    printf("\n\t e        for e raised to the power of any number");
    printf("\n\t s        for sin(x)");
    printf("\n\t c        for cos(x)");
    printf("\n\t t        for tan(x)");
    printf("\n\t i        for sin inverse of x");
    printf("\n\t o        for cos inverse of x");
    printf("\n\t a        for tan inverse of x");
    printf("\n\t 0 to exit the calculator");
    printf("\nStart entering below");
    while (o == 1)
    {
        printf("\nOperator: ");
        fflush(stdin);
        scanf("%c", &a);
        fflush(stdin);
        switch(a)
        {
            case '+':scanf("%f", &fn);
                     scanf("%f", &sn);
                     printf("%f + %f = %f", fn, sn, fn + sn);
                     break;
            case '-':scanf("%f", &fn);
                     scanf("%f", &sn);
                     printf("%f - %f = %f", fn, sn, fn - sn);
                     break;
            case '*':scanf("%f", &fn);
                     scanf("%f", &sn);
                     printf("%f * %f = %f", fn, sn, fn * sn);
                     break;
            case '/':scanf("%f", &fn);
                     scanf("%f", &sn);
                     printf("%f / %f = %f", fn, sn, fn / sn);
                     break;
            case '#':scanf("%d", &f);
                     scanf("%d", &s);
                     printf("Remainder of B%d / %d = %d", f, s, f % s);
                     break;
            case '!':scanf("%d", &f);
                     for (i = 1; i <= f; i++)
                     {
                         t = t * i;
                     }
                     printf("Factorial of %d is %d", f, t);
                     break;
            case 'r':scanf("%f", &fn);
                     printf("Square Root of %f = %f", fn, sqrt(fn));
                     break;
            case '^':scanf("%f", &fn);
                     scanf("%f", &sn);
                     printf("%f raised to the power %f = %f", fn, sn, pow(fn, sn));
                     break;
            case 'l':scanf("%f", &fn);
                     printf("log (%f) = %f", fn, log10(fn));
                     break;
            case 'n':scanf("%f", &fn);
                     printf("Natural log(%f) = %f", fn, log(fn));
                     break;
            case 'e':scanf("%f", &fn);
                     printf("e raised to the power %f = %f", fn, exp(fn));
                     break;
            case 's':scanf("%f", &fn);
                     printf("sin (%f) = %f", fn, sin(fn * (PI / 180)));
                     break;
            case 'c':scanf("%f", &fn);
                     printf("cos (%f) = %f", fn, cos(fn * (PI / 180)));
                     break;
            case 't':scanf("%f", &fn);
                     printf("tan (%f) = %f", fn, tan(fn * (PI / 180)));
                     break;
            case 'i':scanf("%f", &fn);
                     printf("sin inverse of (%f) = %f degrees", fn, asin(fn) * (180 / PI));
                     break;
            case 'o':scanf("%f", &fn);
                     printf("cos inverse of (%f) = %f degrees", fn, acos(fn) * (180 / PI));
                     break;
            case 'a':scanf("%f", &fn);
                     printf("tan inverse of (%f) = %f degrees", fn, atan(fn) * (180 / PI));
                     break; 
            case '0':o = o + 1;
                     break;
            default:printf("\n\tWrong choice");
        }        
        if (a == 0)
            o = o + 1;
    }
    printf("\n\n\t ------------ Thank You ------------");
    return 0;
}