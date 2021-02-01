#include<stdio.h>
main()
{
	int a,ch,c,e=0,d=2;
	printf("1. Odd or Even using ternary operator");
	printf("\n2. Odd or Even using if else");
	printf("\n3. Prime or Composite");
	printf("\nEnter your choice - ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("\nEnter the number - ");
		       scanf("%d",&a);
		       (a%2==0)?printf("Even number"):printf("Odd number");
		       break;
		case 2:printf("\nEnter the number - ");
		       scanf("%d",&a);
		       if(a%2==0)
		       	printf("\nEven number");
		       else
		       	printf("\nOdd number");
		       break;		              
		case 3:printf("\nEnter the number - ");
		       scanf("%d",&a);
		       if(a==1)
		       	printf("\nThe number is neither prime nor composite");
		       else
		       {	
		       	while(d<=a/2)
		       	{
		       		c=a%d;
				if(c==0)
				{
					e=1;
					break;
				}
				d++;
		       	}
		       	if(e==1)
		       		printf("\nComposite number");
		       	else
		       		printf("\nPrime number");
		       }
		       break;
		default:printf("Wrong choice");
	}
}
	
		       
