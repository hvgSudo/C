#include<stdio.h>
int display(int*);
int main()
{
    int fa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr;
    ptr = fa;
    display(ptr);
    return 0;
}

int display(int *ptr) {
    int i;
    for (i = 0; i < 10; i++) {
        printf(" %d ", *ptr);
        ptr ++;
    }
    return(0);
}