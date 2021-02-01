#include<stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 4)
        printf("\nInvalid number of arguments");
    else {
        FILE *fp1 = fopen(argv[1], "r");
        FILE *fp2 = fopen(argv[2], "r");
        FILE *ft = fopen(argv[3], "w");
        if (fp1 == NULL)
            printf("\nError in opening source file 1!");
        if (fp2 == NULL)
            printf("\nError in opening source file 2!");
        if (ft == NULL)
            printf("\nError in opening target file");
        char ch = fgetc(fp1);
        while (ch != EOF) {
            /* display contents of file on screen */
            fputc(ch, ft);
            ch = fgetc(fp1);
        }
        ch = fgetc(fp2);
        while (ch != EOF) {
            /* display contents of file on screen */
            fputc(ch, ft);
            ch = fgetc(fp2);
        }
        if (feof(fp1))
            printf("\nEnd of Source file 1 reached.");
        if (feof(fp2))
            printf("\nEnd of source file 2 reached");
        else
            printf("\n Something went wrong with EOF.");
        printf("\nSuccessfully merged files!");
        fclose(fp1);
        fclose(fp2);
        fclose(ft);
        getchar();
    }
    return 0;
}