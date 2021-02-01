#include <stdio.h>

const int MAX = 100;
int i, j;

void multiplyMatrixRec(int row1, int col1, int A[][MAX],
                       int row2, int col2, int B[][MAX],
                       int C[][MAX])
{
    // Note that below variables are static
    // i and j are used to know current cell of
    // result matrix C[][]. k is used to know
    // current column number of A[][] and row
    // number of B[][] to be multiplied
    static int i = 0, j = 0, k = 0;

    // If all rows traversed.
    if (i >= row1)
        return;

    // If i < row1
    if (j < col2)
    {
        if (k < col1)
        {
            C[i][j] += A[i][k] * B[k][j];
            k++;

            multiplyMatrixRec(row1, col1, A, row2, col2,
                              B, C);
        }

        k = 0;
        j++;
        multiplyMatrixRec(row1, col1, A, row2, col2, B, C);
    }

    j = 0;
    i++;
    multiplyMatrixRec(row1, col1, A, row2, col2, B, C);
}

// Function to multiply two matrices A[][] and B[][]
void multiplyMatrix(int row1, int col1, int A[][MAX],
                    int row2, int col2, int B[][MAX])
{
    int C[MAX][MAX];
    if (row2 != col1)
    {
        printf("Not Possible\n");
        return;
    }

    C[0][0] = 0;

    multiplyMatrixRec(row1, col1, A, row2, col2, B, C);

    // Print the result
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
            printf("%d  ", C[i][j]);

        printf("\n");
    }
}

// Driven Program
int main()
{
    int row1, col1, row2, col2;
    int A[MAX][MAX], B[MAX][MAX];
    printf("\nRow1: ");
    scanf("%d", &row1);
    printf("\nCol1: ");
    scanf("%d", &col1);
    printf("\nRow2: ");
    scanf("%d", &row2);
    printf("\nCol2: ");
    scanf("%d", &col2);
    printf("1:\n");
    for (i = 0; i < row1; i++)
        for (j = 0; j < col1; j++)
            scanf("%d", &A[i][j]);
    printf("2:\n");
    for (i = 0; i < row2; i++)
        for (j = 0; j < col2; j++)
            scanf("%d", &B[i][j]);

    multiplyMatrix(row1, col1, A, row2, col2, B);

    return 0;
}