#include<stdio.h>
main()
{
	int n,d,a=0,b=1,i=1;
	printf("\nEnter the number till where the series has to be made - ");
	scanf("%d",&n);
	printf("\nThe series is as follows - ");
	while(i<=n)
	{
		printf("\n%d",a);
		d=a+b;
		a=b;
		b=d;
		i++;
	}
}
		
		
		
		
		
		
