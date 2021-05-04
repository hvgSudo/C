#include<stdio.h>

void display(int a[][2], int b[][3]) {
	int i, j; 
	for (i = 0; i < 3 ; i++) {
		for (j = 0; j < 2; j++)
			printf("%d  ", a[i][j]);
		printf("\t");
		for (j = 0; j < 3; j++)
			if (i < 2)
				printf("%d  ", b[i][j]);
		printf("\n");
	}
}

int main() {
	int a[3][2], b[2][3];
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 2; j++)
			scanf("%d", &a[i][j]);
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &b[i][j]);
	display(a,b);
	return 0;
}
