#include<stdio.h>
main()
{
	int p,t,i=1;
	float r,si;
	while(i<=5)
	{
		printf("\nEnter the principal - ");
		scanf("%d",&p);
		printf("\nEnter the rate - ");
		scanf("%f",&r);
		printf("\nEnter the time -");
		scanf("%d",&t);
		si=(p*r*t)/100;
		printf("\nSimple Interest for %d is %f",i,si);
		i++;
	}
}
