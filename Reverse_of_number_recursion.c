#include <stdio.h>

void reverse(long long int number) {
    if (number < 10) 
        printf("%lld", number);
    else {
        printf("%lld", number % 10);
        reverse(number / 10);
    }
}

int main() {
    long long int number;
    printf("Enter a number to reverse: ");
    scanf("%d", &number);
    printf("The reversed number: ");
    reverse(number);
    return 0;
}