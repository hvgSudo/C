#include<stdio.h>
int main() {
	int i, a[3], r = 0, *ptr;
	char c;
	do {
		int num = 540;
		printf("Hello World\n");
		
		for (i = 0; i < 3; i ++) {
			r = num % 10;
			num = num / 10;
			a[i] = r;
		}
		ptr = a;
		for (i = 0; i < 3; i ++) {
			printf("%d ", a[i]);
		}
		for (i = 0; i < 3; i ++) {
			printf("\n%d", *ptr);
			ptr ++;
		}
		printf("\nDo you want to continue(y/n): ");
		scanf("%c", &c);
		fflush(stdin);
	}while((c == 'y') || (c == 'Y'));
	return(0);
}
