#include<stdio.h>
#include<conio.h>
void inpt();

void main() {
    inpt();
    inpt();
}

void inpt() {
    char s[20];
    fflush(stdin);
    gets(s);
    fflush(stdin);
    puts(s);
}