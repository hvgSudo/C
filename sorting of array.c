#include<stdio.h>
main()
{
	int i,j,a[5],b=0;
	printf("\nEnter the elements - ");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nThe descending order is \n");
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(a[i]<a[j])
			{
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
		printf("\t%d",a[i]);
	}
	printf("\nThe ascendng order is \n");
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(a[i]>a[j])
			{
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
		printf("\t%d",a[i]);
	}
}
