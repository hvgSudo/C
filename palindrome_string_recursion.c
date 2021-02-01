#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalRec(char str[], int s, int e) {
    if (s == e) // for only one character
        return true;
    if (str[s] != str[e]) // for first and last character
        return false;
    if (s < e + 1) // for more than two characters check if 
        return isPalRec(str, s + 1, e - 1); // middle substring
    return true;
}

bool Palindrome(char str[]) {
    if (strlen(str) == 0) //empty string is palindrome
        return true;
    return isPalRec(str, 0, strlen(str) - 1);
}

int main() {
    char str[20];
    printf("Enter the string to check for palindrome: ");
    scanf("%[^\n]%*c", str);
    if (Palindrome(str));
        printf("%s is a palindrome", str);
    else
        printf("%s is not a plindrome", str);
    return 0;
}