#include<stdio.h>
main()
{
	int a,b,ch,i=0;
	printf("1. Ascending order");
	printf("\n2. Descending order");
	printf("\nEnter your choice - ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("\nEnter the number from where the series starts - ");
		       scanf("%d",&a);
		       printf("\nEnter the number where the series ends - ");
		       scanf("%d",&b);
		       i=a;
		       printf("The ascending series is as follows");
		       while(i<=b)
		       {
		       	printf("\n%d",i);
		       	i++;
		       }
		       break;
		case 2:printf("\nEnter the number from where the series starts - ");
		       scanf("%d",&a); 
		       printf("\nEnter the where the series ends - ");
		       scanf("%d",&b);
		       i=a;
		       printf("\nThe descending order is as follows");
		       while(i>=b)
		       {
		       	printf("\n%d",i);
			i--;
	                 }
	                 break;
	          default:printf("\nWrong choice");
	}
}
