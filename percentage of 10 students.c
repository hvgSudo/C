#include<stdio.h>
main()
{
	int a,b,c,d,e,tot,i=1;
	float per;
	while(i<=10)
	{
		printf("\nEnter the marks of a - ");
		scanf("%d",&a);
		printf("\nEnter the marks of b - ");
		scanf("%d",&b);
		printf("\nEnter the marks of c - ");
		scanf("%d",&c);
		printf("\nEnter the marks of d - ");
		scanf("%d",&d);
		printf("\nEnter the marks of e - ");
		scanf("%d",&e);
		tot=a+b+c+d+e;
		per=tot/5;
		printf("\nThe percentage of %d student is %f",i,per);
		i++;
	}
}
