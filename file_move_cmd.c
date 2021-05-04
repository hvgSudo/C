// only to move one file
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3)
        printf("\nInvalid number of arguments");
    else {
        FILE *fp1 = fopen(argv[1], "r");
        FILE *fp2 = fopen(argv[2], "w");
        if (fp1 == NULL)
            printf("Error in opening source file!");
        if (fp2 == NULL)
            printf("Error in opening destination file!");
        char ch = fgetc(fp1);
        while (ch != EOF) {
            /* display contents of file on screen */
            fputc(ch, fp2);
            ch = fgetc(fp1);
        }
        if (feof(fp1))
            printf("\nEnd of Source file reached.");
        else
            printf("\nSomething went wrong with EOF.");
        printf("\nSuccessfully moved file!");
        fclose(fp1);
        fclose(fp2);
        remove(argv[1]);
        getchar();
    }
    return 0;
}
