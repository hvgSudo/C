#include<stdio.h>
main()
{
	int a,i,r=0,rn=0;
	printf("Enter a number - ");
	scanf("%d",&a);
	i=a;
	while(a!=0)
	{
		r=a%10;
		rn+=r*r*r;
		a=a/10;
	}
	if(i==rn)
		printf("The number %d is an armstrong number",i);
	else
		printf("The number %d is not an armstrong number",i);
}
