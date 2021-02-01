#include<stdio.h>
main()
{
	int a,b,c,d,e,per,tot;
	printf("\nEnter marks of the five Subjects\n");
	printf("Subject 1 - ");
	scanf("%d",&a);
	printf("Subject 2 - ");
	scanf("%d",&b);
	printf("Subject 3 - ");
	scanf("%d",&c);
	printf("Subject 4 - ");
	scanf("%d",&d);
	printf("Subject 5 - ");
	scanf("%d",&e);
	tot = a+b+c+d+e;
	per = tot/5;
	if(per>=60)
		printf("\nFirst Division");
	else if((per>=50)&&(per<=59))
		printf("\nSecond Division");	
	else if((per>=40)&&(per<=49))
		printf("\nThird Division");
	else
		printf("\nBetter Luck Next Time");
}
			
