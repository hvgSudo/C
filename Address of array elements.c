#include<stdio.h>
main()
{
	int i,a[5];
	printf("Enter the elements - ");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<5;i++)
	{
		printf("\nElement - %d",a[i]);
		printf("\nIndex no. - %d",i);
		printf("\nAddress - %u",&a[i]);
	}
} 
