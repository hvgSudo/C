#include<stdio.h>
main()
{
	int a[10],b[5],i=0,j=0,g=0;
	printf("Enter the 5 elements of set 1\n");
	while(i<5)
	{
		scanf("%d",&a[i]);
		i++;
	}
	printf("Enter the 5 elements of set 2\n");
	while(j<5)
	{
		scanf("%d",&b[j]);
		j++;
	}
	printf("\nSet 1 - {");
	for(j=0;j<5;j++)
	{
		printf("%d",a[j]);
		if(j<4)
			printf(",");
	}
	if(j==5)
		printf("}");
	printf("\nSet 2 - {");
	for(i=0;i<5;i++)
	{
		printf("%d",b[i]);
		if(i<4)
			printf(",");
	}
	if(i==5)
		printf("}");
	printf("\nUnion of the two sets - {");
	for(j=0,i=5;i<10;i++)
	{
		a[i]=b[j];
		j++;
	}
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(a[i]>a[j])
			{
				g=a[i];
				a[i]=a[j];
				a[j]=g;
			}
		}
		printf("%d",a[i]);
		if(i<9)
			printf(",");
	}
	if(i==10)
		printf("}");
	printf("\nIntersection of the two sets - {");
	for(i=0;i<10;i++)
	{
		j=i+1;
		if(a[i]==a[j])
			printf("%d,",a[i]);
	}
	if(i==10)
		printf("}");
}
