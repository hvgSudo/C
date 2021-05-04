#include<stdio.h>
main()
{
	int i,p[30],c[30],m[30],e[30],cs[30],tot;
	float per;
	for(i=0;i<30;i++)
	{
		printf("\nStudent no. %d",i+1);
		printf("\nEnter the marks of Physics - ");
		scanf("%d",&p[i]); 
		printf("\nEnter the marks of Chemistry - ");
		scanf("%d",&c[i]);
		printf("\nEnter the marks of Mathematics - ");
		scanf("%d",&m[i]);
		printf("\nEnter the marks of English - ");
		scanf("%d",&e[i]);
		printf("\nEnter the marks of Computer Science - ");
		scanf("%d",&cs[i]);
	}
	for(i=0;i<30;i++)
	{
		tot=p[i]+c[i]+m[i]+e[i]+cs[i];
		per=tot/5;
		printf("\nThe percentage of student no. %d is %f",i+1,per);
	}
}
