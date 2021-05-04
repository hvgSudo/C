#include<stdio.h>
main()
{
	int a,n,r=0,rn=0;
	printf("Enter the number - ");
	scanf("%d",&n);
	a=n;
	while(n!=0)
	{
		r=n%10;
		rn=10*rn+r;
		n=n/10;
	}
	if(a==rn)
		printf("The number is a palindrome number");
	else
		printf("The number is not a palindrome number");
}
