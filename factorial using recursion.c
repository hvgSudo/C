#include<stdio.h>
int factorial(int);
main()
{
  int a;
  printf("Enter any number - ");
  scanf("%d",&a);
  printf("Factorial of the number - %d",factorial(a));
}
int factorial(int x)
{
  int f=1;
  if(x==1)
    return(1);
  else
    f=x*factorial(x-1);
  return(f);
}
