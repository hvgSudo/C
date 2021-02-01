#include<stdio.h>
main()
{
	int a,b;
	printf("\n Enter a and b\n");
	scanf("%d%d",&a,&b);
	a = a+b;
	b = a-b;
	a = a-b;
	printf("\n a after swap = %d    b after swap = %d",a,b);
	//printf("\n b after swap = %d",b);
}
