#include<stdio.h>
main()
{
	char ch;
	int a,b,add,sub,mul;
	float div;
	printf("\nEnter a - ");
	scanf("%d",&a);
	fflush(stdin);
	printf("\nEnter b - ");
	scanf("%d",&b);
	fflush(stdin);
	printf("\n '+' to add");
	printf("\n '-' to subtract");
	printf("\n '*' to multiply");
	printf("\n '/' to divide");
	printf("\n Enter your choice - ");
	fflush(stdin);
	scanf("%c",&ch);
	switch(ch)
	{
		case '+':add=a+b;
		         printf("\n Addition - %d",add);
		         break;
		case '-':sub=a-b;
		         printf("\n Subtracion - %d",sub);
		         break;
		case '*':mul=a*b;
		         printf("\n Multiplication - %d",mul);
		         break;
		case '/':div=a/b;
		         printf("\n Division - %f",div);
		         break;                   
		default:printf("\n Wrong Choice");
	}
}
