#include<stdio.h>
main()
{
	int a;
	float b;
	char c;
	double d;
	printf("Size of a - %d",sizeof(a));
	printf("\nAddress of a - %u",&a);
	printf("\n\nSize of b - %d",sizeof(b));
	printf("\nAddress of b - %u",&b);
	printf("\n\nSize of c - %d",sizeof(c));
	printf("\nAddress of c - %u",&c);
	printf("\n\nSize of d - %d",sizeof(d));
	printf("\nAddress of d - %u",&d);
}
