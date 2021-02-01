#include<stdio.h>
main()
{
	int n,a,i=0,r=0,rn=0;
	printf("Enter the number - ");
	scanf("%d",&n);
	rn=n;
	printf("\nEnter the digit whose frequency is to be found - ");
	scanf("%d",&a);
	while(n!=0)
	{
		r=n%10;
		if(a==r)
			i+=1;
		n=n/10;
	}
	printf("\nThe digit %d is present %d times in %d",a,i,rn);
}
