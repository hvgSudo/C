#include<stdio.h>
main()
{
	int cm;
	float feet;
	printf("\n Enter length in cms - ");
	scanf("%d",&cm);
	feet = cm*0.032808;
	printf("\n Length in feet - %f",feet);
}
