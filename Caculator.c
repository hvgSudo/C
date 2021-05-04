#include<stdio.h>
main()
{
	int a,b,add,sub,mul;
	float div;
	printf("Enter a and b\n");
	scanf("%d%d",&a,&b);
	add = a+b;
	sub = a-b;
	mul = a*b;
	div = a/b;
	printf("\n Addition = %d",add);
	printf("\n Subtraction = %d",sub);
	printf("\n Multiplication = %d",mul);
	printf("\n Division = %f",div);
}
