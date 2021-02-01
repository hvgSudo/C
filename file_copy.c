#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *fptr = fopen("D:\\Codes\\C\\Source.txt", "r");
    FILE *fpt = fopen("D:\\Codes\\C\\s.txt", "w");
    char ch = getc(fptr);
    while (ch != EOF) {
        fputc(ch, fpt);
        ch = getc(fptr);
    }
    if (feof(fptr)) 
        printf("\nEnd of file");
    else
        printf("\nSomething went wrong");
    printf("\nFile copied successfully");
    fclose(fptr);
    fclose(fpt);
    return 0;
}