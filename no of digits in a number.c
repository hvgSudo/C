#include<stdio.h>
main()
{
	int a,r=0,i=0;
	printf("Enter the number - ");
	scanf("%d",&a);
	while(a!=0)
	{
		r=a%10;
		i+=1;
		a=a/10;
	}
	printf("\nTotal number of digits in the given number - %d",i);
}
