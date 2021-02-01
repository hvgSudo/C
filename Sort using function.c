#include<stdio.h>
void sort(int);
main()
{
	int b=0;
	sort(b);
}
void sort(int h)
{
	int i,j,a[5];
	printf("\nEnter the elements - ");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nThe ascendng order is \n");
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(a[i]>a[j])
			{
				h=a[i];
				a[i]=a[j];
				a[j]=h;
			}
		}
		printf("\t%d",a[i]);
	}
}
