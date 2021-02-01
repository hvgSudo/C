#include <stdio.h>
#include <stdlib.h>
struct threenum
{
    int n1, n2, n3;
}num;
int main()
{
    int n;
    //struct threenum num;
    FILE  *fptr;
    if ((fptr = fopen("D:\\num.bin", "rb")) == NULL)
    {
        printf("Error!opening file");
        exit(1);
    }
    for (n = 1; n < 5; ++n)
    {

        fread(&num, sizeof(struct threenum), 1, fptr);
        printf(" %d %d %d ", num.n1, num.n2, num.n3);
    }
    fclose(fptr);
    return 0;
}
