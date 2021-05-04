#include<stdio.h>
#include<math.h>
main()
{
	int a,b,c,d;
	float root1,root2;
	printf("Enter a,b,c of the quadratic equation ax2+bx+c=0\n");
	scanf("%d%d%d",&a,&b,&c);
	d = b*b - 4*a*c;
	if(d>=0)
	{
		root1 = (-b+sqrt(d))/(2*a);
		root2 = (-b-sqrt(d))/(2*a);
		printf("Root1 = %f",root1);
		printf("\n Root2 = %f",root2);
          }
	else 
	{
		printf("Roots are imaginary");
	} 
}
