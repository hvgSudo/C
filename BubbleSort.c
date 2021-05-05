#include<stdio.h>
#include<stdlib.h>

void initCode() {
	// fast_io;
	#ifndef ONLINE_JUDGE
  
    // For getting input from input.txt file
    freopen("D:/Codes/C/input.txt", "r", stdin);
  
    // Printing the Output to output.txt file
    freopen("D:/Codes/C/output.txt", "w", stdout);
  
	#endif
}

int main()
{
	initCode();
	int i,j,a[5],b=0;
	// printf("\nEnter the elements - ");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nThe descending order is \n");
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(a[i]<a[j])
			{
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
		printf("\t%d",a[i]);
	}
	printf("\nThe ascendng order is \n");
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(a[i]>a[j])
			{
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
		printf("\t%d",a[i]);
	}
	return 0;
}
