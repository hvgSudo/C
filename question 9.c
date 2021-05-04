#include<stdio.h>
main()
{
	int i,j,a=0,b=0,d=0,f=0,g=0,k=0;
	char ch[10],c[20],e[5],h[10];
	printf("Enter the first string - ");
	gets(ch);
	for(i=0;ch[i]!='\0';i++)
		a+=1;
	fflush(stdin);
	printf("\nEnter the second string - ");
	gets(c);
	for(i=0;c[i]!='\0';i++)
	{
		h[i]=c[i];
		b+=1;
	}
	for(i=0;i<a;i++)
	{
		if(ch[i]==c[i])
			d+=1;
	}
	for(j=0,i=b;i<a+b;i++)
	{
		if(j<a)
			c[i]=ch[j];
		j++;
	}
	printf("\nEnter the substring to be found - ");
	gets(e);
	for(i=0;e[i]!='\0';i++)
		f+=1;
	for(i=0;i<=a-f;i++)
	{
		for(k=0;k<f;k++)
			if(ch[i+k]!=e[k])
				break;
		if(k==f)
		{
			g++;
			k=0;
		}
	}
	if(d==a)
		printf("\nThe strings are equal");
	else
		printf("\nThe strings are not equal");	
	if(a>b)
		printf("\nThe first string is longer");
	else if(b>a)
		printf("\nThe second string is longer");
	else
		printf("\nLength of both the strings is equal");
	printf("\nThe concatenated string is %s%s",ch,h);
	printf("\nThe copied string is %s",c);
	if(g>=1)
		printf("\n%s is present in %s",e,ch);
	else
		printf("\n%s is not present in %s",e,ch);
}
			
		
		
		
		
		
		
	
