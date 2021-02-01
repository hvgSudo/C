#include<stdio.h>
struct puranjay
{
	int a;
	char name[20];
};
main()
{
	int i;
	for(i=0;i<10;i++)
	{
		struct puranjay s1;
		printf("Enter the age ");
		scanf("%d",&s1.a);
		printf("\nEnter the name ");
		scanf("%s",&s1.name);
	}
	for(i=0;i<10;i++)
	{
		printf("\n%d\t%s",s1.a,s1.name);
	}
}
