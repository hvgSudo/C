#include<stdio.h>
int main()
{
	int a[3][3],b[3][3],i,j;
	printf("Enter the elements of the 3x3 matrix 1\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the elements of the 3x3 matrix 2\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	printf("The matrix 1 is");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("  %d",a[i][j]);
		}
	}
	printf("\nThe matrix 2 is");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("  %d",b[i][j]);
		}
	}
	printf("\nAddition of matrix 1 and 2 is");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("  %d",a[i][j]+b[i][j]);
		}
	}
	printf("\nSubtraction of matrix 1 from 2 is");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("\t%d",b[i][j]-a[i][j]);
		}
	}
	printf("\nTranspose of matrix 1 and 2 is");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("  %d",a[j][i]);
		}
	}
	for(i=0;i<3;i++)
	{
		printf("\n\t");
		for(j=0;j<3;j++)
		{
			printf("  %d",b[j][i]);
		}
	}
	return 0;			
}
