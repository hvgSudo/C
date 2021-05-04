#include<stdio.h>

int main() {
    int input, i, j, arr[100];
    while(1 == 1) {
        scanf("%d", &input);
        if (input == 42)
            break;
        else {
            arr[i] = input;
            i = i + 1;
        }
    }
    for (j = 0; j < i; j++) 
        printf("\n%d", arr[j]);
    return 0;
}