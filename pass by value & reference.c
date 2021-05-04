#include<stdio.h>
void display(int);
void play(int *);
main()
{
	int a[5],i;
	printf("Enter the array - ");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<5;i++)
	{
		display(a[i]);
	}
	for(i=0;i<5;i++)
	{
		play(&a[i]);
	}
}
void display(int b)
{
	printf("  %d",b);
}
void play(int *c)
{
	printf("\n%d\n",*c);
}
