#include<stdio.h>
#include<stdlib.h>

int main() {
    int i;
    FILE *fptr;
    fptr = fopen("D\\Test.txt");
    for (i = 0; i < fptr.length(); i++)
        printf("%c ", i);
    fclose(fptr);
    return 0;
}