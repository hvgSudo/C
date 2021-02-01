#include<stdio.h>
main()
{
	int p,t;
	float r,si;
	printf("Enter Principal - ");
	scanf("%d",&p);
	printf("\n Enter Rate - ");
	scanf("%f",&r);
	printf("\n Enter Time - ");
	scanf("%d",&t);
	si = (p*r*t)/100;
	printf("\n Simple Interest = %f",si);
}
