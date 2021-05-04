#include<stdio.h>
int main()
{
	int a = 9;
	int &b = a;
	a ++;
	printf("%d", b);
	return 0;
}
