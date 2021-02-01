#include<stdio.h>
main()
{
	int n,i,a=1;
	printf("\nEnter the number whose factorial is to be found - ");
	scanf("%d",&n);
	i=1;
	printf("\nThe factorial of %d is ",n);
	while(i<=n)
	{
		a*=i;
		printf("%d",i);
		if(i<n)
			printf(" x ");
		i++;
	}
	printf(" = %d",a);
}
		
