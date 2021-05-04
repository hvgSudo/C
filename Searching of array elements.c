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
	printf("\nThere are 5 elements in the array");
	for(i=0;i<5;i++)
	{
		if(a[i]==b)
		{
			printf("\nThe number found at %d postion",i+1);
			for(j=i+1;j<5;j++)
			{
				if(a[j]==b)
					printf("\nThe number also found at %d postion",j+1);
			}
			break;
		}
	}
	if(i==5)
		printf("\nThe number not found");
}
