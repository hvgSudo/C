#include<stdio.h>
void array(int *,int);
main()
{
	int a[5],b[5],c[5],i;
	printf("Enter the first array - ");
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	printf("Enter the second array - ");
	for(i=0;i<5;i++)
		scanf("%d",&b[i]);
	for(i=0;i<5;i++)
		c[i]=a[i]+b[i];
	printf("\nThe resultant array containing the sum is -\n");			
	array(&c[0],5);
}
void array(int *j,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",*j);
		j++;
	}
}
