#include<stdio.h>
main()
{
	int a[5],b,i=0,j=0;
	printf("Enter the numbers - ");
	while(i<5)
	{
		scanf("%d",&a[i]);
		i++;
	}
	printf("\nEnter the number to be found - ");
	scanf("%d",&b);
	while(j<5)
	{
		if(b==a[j])
		{
			printf("\nThe number is found at %d positon",j+1);
			break;
		}
		else
			break;
		j++;
	}
	printf("\nThe number not found in the array");
}
