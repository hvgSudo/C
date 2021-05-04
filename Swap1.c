#include<stdio.h>
int main()
{
	int a,b,c;
	printf("\n Enter a and b\n");
	scanf("%d%d",&a,&b);
	c=a;
	a=b;
	b=c;
	printf("\n a after swap = %d",a);
	printf("\n b after swap = %d",b);
	return(0);
}
