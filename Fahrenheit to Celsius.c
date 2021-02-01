#include<stdio.h>
main()
{
	int f,c;
	float temp,tem;
	printf("\n Enter temperature in celsius - ");
	scanf("%d",&c);
	printf("\n Enter Temperature in Fahrenheit - ");
	scanf("%d",&f);
	temp=((9*c)/5)+32;
	tem=((f-32)*5)/9;
	printf("\n Temperature in Fahreheit is - %f",temp);
	printf("\n Temperature in Celsius - %f",tem);
}
