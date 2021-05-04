#include<stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2)
        printf("\nInvalid number of arguments");
    else {
        FILE *fp1 = fopen(argv[1], "r");
        if (fp1 == NULL)
            printf("Error in opening source file!");
        char ch = fgetc(fp1);
        while (ch != EOF) {
            /* display contents of file on screen */
            putchar(ch);
            ch = fgetc(fp1);
        }
        if (feof(fp1))
            printf("\n End of Source file reached.");
        else
            printf("\n Something went wrong with EOF.");
        fclose(fp1);
        getchar();
    }
    return 0;
}