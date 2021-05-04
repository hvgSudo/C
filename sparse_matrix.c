#include<stdio.h>

int main() {
    int i, j, k, size;
    int matrix[4][5];
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            if (matrix[i][j] != 0)  
                size++;
    int compactmatrix[3][size];
    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            if (matrix[i][j] != 0) {
                compactmatrix[0][k] = i;
                compactmatrix[1][j] = j;
                compactmatrix[2][k] = matrix[i][j];
                k++;
            }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < size; j++)
            printf("%d ", compactmatrix[i][j]);
        printf("\n");
    }
    return 0;
}