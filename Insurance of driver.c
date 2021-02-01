#include<stdio.h>
main()
{
	char ms,g;
	int age;
	printf("Enter Marital Status 'm' for married and 'u' for unmarried - ");
	scanf("%c",&ms);
	fflush(stdin);
	printf("\nEnter gender 'l' for male and 'f' for female - ");
	scanf("%c",&g);
	fflush(stdin);
	printf("\nEnter age - ");
	scanf("%d",&age);
	if(ms=='m')
		printf("\nInsured");
	else if(ms=='u')
	{
		if((g=='l')&&(age>30))
			printf("\nInsured");
		if((g=='f')&&(age>25))
			printf("\nInsured");
		else
			printf("\nNot Insured");
	}
}

