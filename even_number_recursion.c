#include<stdio.h>

int Even(int k) {
    if (k == 1)
        return 0;
    else
        return Even(k - 1) + 2;
}

int main() {
    int i;
    for (i = 0; i < 10; i++) 
        printf("\n%d Even Natural Number: %d", i+1, Even(i+1));
    return 0;
}