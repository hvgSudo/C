#include<stdio.h>
int main()
{
	int n,i;
	char c;
	do
	{
		printf("\n\t%c",i);
		i++;
		printf("Do you want to continue (y/n): ");
		scanf("%c",&c);
	}while(c == 'y'||c=='Y');
	return 0;
}
