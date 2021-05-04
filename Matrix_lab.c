#include<stdio.h>

int i, j, max = 20;
char cha;

void multiplication(int m, int n, int a[][max], int p, int q, int b[][max], int mult[][max]) {
    static int l = 0, o = 0, k = 0;
    int add = 0;
    if (l >= m)
        return;
    if (o < q) {
        if (k < n) {
            mult[l][o] += a[l][k] * b[k][o];
            k += 1;
            multiplication(m, n, a, p, q, b, mult);
        }
        k = 0;
        o += 1;
        multiplication(m, n, a, p, q, b, mult);
    }
    o = 0;
    l += 1;
    multiplication(m, n, a, p, q, b, mult);
}

void greatest_num_row(int m, int n, int a[][max]) {
    int temp;
    for (i = 0; i < m; i++) {
        temp = 0;
        for(j = 0; j < n; j++) {
            if (temp == 0)
                temp = a[i][j];
            else if (temp < a[i][j])
                temp = a[i][j];
        }
        printf("\nGreatest number in row %d: %d", i + 1, temp);
    }
}

void add_maj_diagonal_ele(int m, int n, int a[][max]) {
    int sum = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                if (i <= n - 1 && j == n - 1)
                    printf("%d", a[i][j]);
                else
                    printf("%d + ", a[i][j]);
                sum += a[i][j];
            }
        }
    }
    printf(" = %d", sum);
}

void sparse_matrix(int u, int v, int e[][max]) {
    int k = 0;
    int x[max][3];
    for (i = 0; i < u; i++) {
        for (j = 0; j < v; j++)
            if (e[i][j] != 0) {
                x[k][0] = i;
                x[k][1] = j;
                x[k][2] = e[i][j];
                k++;
            }
    }
    printf("\nSparse Matrix: \n");
    for (i = 0; i < k; i++) {
        for (j = 0; j < 3; j++)
            printf("%d  ", x[i][j]);
        printf("\n");
    }
}

void add_sparse(int m, int n, int e[][max], int f[][max]) {
    int k = 0, l = 0, r = 0;
    int w[max][max];
    for (i = 0; i < m; i++) // Adding the original matrix
        for (j = 0; j < n; j++)
            w[i][j] = e[i][j] + f[i][j];
    int x[max][3];
    for (i = 0; i < m; i++) // sparse matrix for matrix 1
        for (j = 0; j < n; j++)
            if (e[i][j] != 0) {
                x[k][0] = i;
                x[k][1] = j;
                x[k][2] = e[i][j];
                k++;
            }
    int y[max][3];
    for (i = 0; i < m; i++) // sparse matrix for matrix 2
        for (j = 0; j < n; j++)
            if (f[i][j] != 0) {
                y[l][0] = i;
                y[l][1] = j;
                y[l][2] = f[i][j];
                l++;
            }
    int z[max][3];
    for (i = 0; i < m; i++) // sparse matrix for the resultant matrix
        for (j = 0; j < n; j++)
            if (w[i][j] != 0) {
                z[r][0] = i;
                z[r][1] = j;
                z[r][2] = w[i][j];
                r++;
            }
    printf("\nSum of sparse matrix: \n"); // output
    if ( k >= l) {
        for (i = 0; i < k; i++) {
            for (j = 0; j < 3; j++)
                printf("%d  ", x[i][j]);
            printf(" \t ");
            for (j = 0; j < 3; j++) {
                if (i < l)
                    printf("%d  ", y[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for ( i = 0; i < r; i++) {
            for (j = 0; j < 3; j++)
                printf("%d  ", z[i][j]);
            printf("\n");
        }
    } else {
        for (i = 0; i < l; i++) {
            for (j = 0; j < 3; j++)
                printf("%d  ", y[i][j]);
            printf(" \t ");
            for (j = 0; j < 3; j++) {
                if ( i < k)
                    printf("%d  ", x[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for (i = 0; i < r; i++) {
            for (j = 0; j < 3; j++)
                printf("%d  ", z[i][j]);
            printf("\n");
        }
    }
}

void sparse_transpose(int m, int n, int g[][max]) {
    int k = 0, t = 0, temp = 0, tem = 0, te = 0, h[max][max], transpose[max][max];
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (g[i][j] != 0) {
                h[k][0] = i;
                h[k][1] = j;
                h[k][2] = g[i][j];
                k++;
            }
    printf("\nSparse Matrix: ");
    for ( i = 0; i < k; i++) {
        printf("\n");
        for (j = 0; j < 3; j++)
            printf("%d  ", h[i][j]);
    }
    for (i = 0; i <= k; i++)
        for (j = 0; j <= 3; j++)
            transpose[i][j] = 0;
    t = k;
    for (i = 0; i < t; i++) { // initialization of transpose matrix
        transpose[i][0] = h[i][1];
        transpose[i][1] = h[i][0];
        transpose[i][2] = h[i][2];
    }
    for (i = 0; i < t; i++) { // sorting according to columns turned rows
        temp = transpose[i][0];
        tem = transpose[i][1];
        te = transpose[i][2];
        j = i - 1;
        while (j >= 0 && transpose[j][0] > temp) {
            transpose[j+1][0] = transpose[j][0];
            transpose[j + 1][1] = transpose[j][1];
            transpose[j + 1][2] = transpose[j][2];
            j = j - 1;
        }
        transpose[j + 1][0] = temp;
        transpose[j + 1][1] = tem;
        transpose[j + 1][2] = te;
    }
    printf("\nTranspose of the matrix: ");
    for (i = 0; i < t; i++) {
        printf("\n");
        for(j = 0; j < 3; j++)
            printf("%d  ", transpose[i][j]);
    }
}

int main() {
    int choice, ch, m, n, p, q;
    int a[max][max], b[max][max], mult[max][max];
    printf("\nEnter the number of rows in matrix 1: ");
    scanf("%d", &m);
    printf("\nEnter the number of columns in matrix 1: ");
    scanf("%d", &n);
    printf("Enter elements of the matrix 1: ");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("\nEnter the number of rows in matrix 2: ");
    scanf("%d", &p);
    printf("\nEnter the number of columns in matrix 2: ");
    scanf("%d", &q);
    printf("Enter elements of the matrix 2: ");
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++)
            scanf("%d", &b[i][j]);
    for (i = 0; i < m; i++)
        for (j = 0; j < q; j++)
            mult[i][j] = 0;
    do {
        printf("\n1. Display matrices");
        printf("\n2. Addition of two matrices");
        printf("\n3. Subtraction of two matrices");
        printf("\n4. Multiplication of two matrices");
        printf("\n5. Greatest number from each row");
        printf("\n6. Addition of major diagonal elements");
        printf("\n7. Sparse matrix representation for the given matrix");
        printf("\n8. Add sparse matrices");
        printf("\n9. Transpose of the sparse matrix");
        printf("\n10. Enter new matrices");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nMatrix 1 \t\t Matrix 2");
                if (m > p) {
                    for (i = 0; i < m; i++) {
                        printf("\n");
                        for (j = 0; j < n; j++)
                            printf("%d  ", a[i][j]);
                        printf("\t\t");
                        for (j = 0; j < q; j++)
                            if (i < p)
                                printf("%d  ", b[i][j]);
                    }
                } else {
                    for (i = 0; i < p; i++) {
                        printf("\n");
                        for (j = 0; j < n; j++)
                            if (i < m)
                                printf("%d  ", a[i][j]);
                        printf("\t\t");
                        if (i == p - 1 && !(m == p) && !(n == q))
                            printf("\t");
                        for (j = 0; j < q; j++)
                            printf("%d  ", b[i][j]);
                    }
                }
                break;
                case 2:
                    if (m == p && n == q)
                    {
                        for (i = 0; i < m; i++)
                        {
                            printf("\n");
                            for (j = 0; j < n; j++)
                                printf("%d   ", a[i][j]);
                            printf(" \t ");
                            if (i == m / 2)
                                printf(" +\t ");
                            else
                                printf(" \t ");
                            for (j = 0; j < n; j++)
                                printf("%d   ", b[i][j]);
                            printf(" \t ");
                            if (i == m / 2)
                                printf(" =\t ");
                            else
                                printf(" \t ");
                            for (j = 0; j < n; j++)
                                printf("%d   ", a[i][j] + b[i][j]);
                        }
                    }
                    else
                        printf("\nAddition not possible");
                    break;
                case 3:
                    if (m == p && n == q)
                    {
                        for (i = 0; i < m; i++)
                        {
                            printf("\n");
                            for (j = 0; j < n; j++)
                                printf("%d   ", a[i][j]);
                            printf(" \t ");
                            if (i == m / 2)
                                printf(" -\t ");
                            else
                                printf(" \t ");
                            for (j = 0; j < n; j++)
                                printf("%d   ", b[i][j]);
                            printf(" \t ");
                            if (i == m / 2)
                                printf(" =\t ");
                            else
                                printf(" \t ");
                            for (j = 0; j < n; j++)
                                printf("%d   ", a[i][j] - b[i][j]);
                        }
                    }
                    else
                        printf("\nSubtraction not possible");
                    break;
                case 4:
                    if (n == p)
                    {
                        if (m >= p)
                        {
                            for (i = 0; i < m; i++)
                            {
                                printf("\n");
                                for (j = 0; j < n; j++)
                                    printf("%d  ", a[i][j]);
                                printf("\t");
                                for (j = 0; j < q; j++)
                                    if (i < p)
                                        printf("%d  ", b[i][j]);
                            }
                            multiplication(m, n, a, p, q, b, mult);
                            printf("\nProduct: \n");
                            for (i = 0; i < m; i++)
                            {
                                fflush(stdin);
                                for (j = 0; j < q; j++)
                                    printf("%d  ", mult[i][j]);
                                printf("\n");
                            }
                        }
                        else
                        {
                            for (i = 0; i < p; i++)
                            {
                                printf("\n");
                                for (j = 0; j < n; j++)
                                    if (i < m)
                                        printf("%d  ", a[i][j]);
                                if (i == m)
                                    printf("\t");
                                printf("\t");
                                for (j = 0; j < q; j++)
                                    printf("%d  ", b[i][j]);
                            }
                            multiplication(m, n, a, p, q, b, mult);
                            printf("\nProduct: \n");
                            for (i = 0; i < m; i++)
                            {
                                fflush(stdin);
                                for (j = 0; j < q; j++)
                                    printf("%d  ", mult[i][j]);
                                printf("\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\nMatrix multiplication not possible");
                    }
                    break;
                case 5:
                    printf("\nWhich matrix do you want to operate on(1 or 2): ");
                    scanf("%d", &ch);
                    if (ch == 1) {
                    	printf("Matrix 1: \n");
                        for (i = 0; i < m; i++) {
                            for (j = 0; j < n; j++)
                                printf("%d  ", a[i][j]);
                            printf("\n");
                        }
                        greatest_num_row(m, n, a);
                    } else if (ch == 2) {
                    	printf("Matrix 2: \n");
                        for (i = 0; i < p; i++) {
                            for (j = 0; j < q; j++)
                                printf("%d  ", b[i][j]);
                            printf("\n");
                        }
                        greatest_num_row(p, q, b);
                    } else {
                        printf("\nInvalid input");
                        break;
                    }
                    break;
                case 6:
                    printf("\nWhich matrix do you want to operate on(1 or 2): ");
                    scanf("%d", &ch);
                    if (ch == 1) {
                    	printf("Matrix 2: \n");
                        for (i = 0; i < p; i++) {
                            for (j = 0; j < q; j++)
                                printf("%d  ", b[i][j]);
                            printf("\n");
                        }
                        printf("Sum of major diagonal elements\n\t");
                        add_maj_diagonal_ele(m, n, a);
                    } else if (ch == 2) {
                    	printf("Matrix 2: \n");
                        for (i = 0; i < p; i++) {
                            for (j = 0; j < q; j++)
                                printf("%d  ", b[i][j]);
                            printf("\n");
                        }
                        printf("Sum of major diagonal elements\n\t");
                        add_maj_diagonal_ele(p, q, b);
                    } else {
                        printf("\nInvalid input");
                        break;
                    }
                    break;
                case 7:
                    printf("\nWhich matrix do you want to operate on(1 or 2): ");
                    scanf("%d", &ch);
                    if (ch == 1)
                    {
                        printf("Matrix 1: \n");
                        for (i = 0; i < m; i++)
                        {
                            for (j = 0; j < n; j++)
                                printf("%d  ", a[i][j]);
                            printf("\n");
                        }
                        sparse_matrix(m, n, a);
                    }
                    else if (ch == 2)
                    {
                        printf("Matrix 2: \n");
                        for (i = 0; i < p; i++)
                        {
                            for (j = 0; j < q; j++)
                                printf("%d  ", b[i][j]);
                            printf("\n");
                        }
                        sparse_matrix(p, q, b);
                    }
                    else
                        printf("\nInvalid input");
                    break;
                case 8:
                    if (m == p && n == q)
                        add_sparse(m, n, a, b);
                    else
                        printf("\nAddition not possible since the size of the matrices are not equal");
                    break;
                case 9:
                    printf("\nWhich matrix do you want to operate on(1 or 2): ");
                    scanf("%d", &ch);
                    if (ch == 1) {
                        printf("Matrix 1: \n");
                        for (i = 0; i < m; i++) {
                            for (j = 0; j < n; j++)
                                printf("%d  ", a[i][j]);
                            printf("\n");
                        }
                        sparse_transpose(m, n, a);
                    } else if (ch == 2) {
                        printf("Matrix 2: \n");
                        for (i = 0; i < p; i++) {
                            for (j = 0; j < q; j++)
                                printf("%d  ", b[i][j]);
                            printf("\n");
                        }
                        sparse_transpose(p, q, b);
                    }
                    else
                        printf("\nInvalid input");
                    break;
                case 10:
                    main();
                    break;
                default:
                    printf("\nWrong choice");
                }
        printf("\nDo you want to conduct more operations(y/n): ");
        fflush(stdin);
        scanf("%c", &cha);
    }while(cha == 'y' || cha == 'Y');
    return 0;
}
