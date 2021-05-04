#include<stdio.h>
main()
{
	char q,g;
	int e;
	printf("\nEnter Gender (m/f) - ");
	scanf("%c",&g);
	fflush(stdin);
	printf("\nEnter Qualification 'p' for post graduate 'g' for graduate - ");
	scanf("%c",&q);
	fflush(stdin);
	printf("\nEnter Experience in years - ");
	scanf("%d",&e);
	if(g=='m')
	{
		if((e>=10)&&(q=='p'))
			printf("\nSalary - 15000");
		else if((e>=10)&&(q=='g'))
			printf("\nSalary - 10000");
		else if((e<10)&&(q=='p'))
			printf("\nSalary - 10000");
		else if((e<10)&&(q=='g'))
			printf("\nSalary - 7000");
	}
	else
	{
		
		if((e>=10)&&(q=='p'))
			printf("\nSalary - 12000");
		else if((e>=10)&&(q=='g'))
			printf("\nSalary - 9000");
		else if((e<10)&&(q=='p'))
			printf("\nSalary - 10000");
		else if((e<10)&&(q=='g'))
			printf("\nSalary - 6000");
	}
}
