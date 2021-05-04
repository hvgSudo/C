#include<stdio.h>
main()
{
	int a,b,i=1;
	printf("\nEnter th enumber whose multiplication table is to be found - ");
	scanf("%d",&a);
	printf("\nThe multiplication table of %d is - ",a);
	while(i<=10)
	{
		b=a*i;
		printf("\n%d x %d = %d",a,i,b);
		i++;
	}
}
