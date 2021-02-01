#include<stdio.h>
main()
{
	int a,b,c;
	printf("Enter a,b,c");
	scanf("%d%d%d",&a,&b,&c);
	if((a>b)&&(a>c))
	{
		printf("\n a is greatest");
	}
	else if((b>a)&&(b>c))
	{
		printf("\n b is greatest");
	}
	else
	{
		printf("\n c is greatest");
	}
}
