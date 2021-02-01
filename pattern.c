#include<stdio.h>
main()
{
	int i,j;
	printf("\nFirst Pattern");
	for(i=1;i<=5;i++)
	{
		printf("\n");
		for(j=1;j<=i;j++)
		{
			printf(" * ");
		}
	}
	printf("\nSecond Pattern");
	for(i=1;i<=5;i++)
	{
		printf("\n");
		for(j=1;j<=5;j++)
		{
			printf(" * ");
		}
	}
	printf("\nThird Pattern");
	for(i=5;i>=1;i--)
	{
		printf("\n");
		for(j=i;j>=1;j--)
		{
			printf(" * ");
		}
	}
	printf("\nFourth pattern");
	for(i=1;i<=5;i++)
	{
		printf("\n");
		for(j=1;j<=i;j++)
		{
			printf(" * ");
		}
	}
	for(i=5;i>=1;i--)
	{
		printf("\n");
		for(j=i;j>=1;j--)
		{
			printf(" * ");
		}
	}
	printf("\nFifth pattern");
	for(i=1;i<=5;i++)
	{
		printf("\n");
		for(j=1;j<=i;j++)
		{
			printf(" * ");
		}
	}
	for(i=1;i<=5;i++)
	{
		printf("\n");
		for(j=1;j<=5;j++)
		{
			printf(" * ");
		}
	}
	for(i=5;i>=1;i--)
	{
		printf("\n");
		for(j=i;j>=1;j--)
		{
			printf(" * ");
		}
	}
}
