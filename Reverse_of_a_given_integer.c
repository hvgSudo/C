#include<stdio.h>
main()
{
	int a,r=0,rn=0;
	printf("Enter the number (atleast 2 digit) - ");
	scanf("%d",&a);
	while(a!=0)
	{
		r=a%10;
		rn=rn*10+r;
		a=a/10;
		
	}
	printf("\nThe reverse is - %d",rn);
}
