#include<stdio.h>
main()
{
	int i=0,j=0,k=0,l=0,m=0,n=0,h=0;
	char c[10],t[10],ch[10];
	printf("Enter the string - ");
	gets(c);
	for(i=0;c[i]!='\0';i++)
	{
		ch[i]=c[i];
		k+=1;
		if((c[i]!='\0') && (c[i]!=' '))		
			l+=1;
		if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u')	
			m+=1;
		if(c[i]=='A'||c[i]=='E'||c[i]=='I'||c[i]=='O'||c[i]=='U')
			n+=1;	
	}
	printf("\nLength of the string - %d",k);
	printf("\nTotal number of characters in the string - %d",l);
	printf("\nTotal number of vowels in the string - %d",m+n);
	printf("\nThe reverse of the string is - ");
	for (i = k; i >= 0 ; i--)
    	{
        		t[k - i - 1] = ch[i];
        		printf("%c",t[k-i-1]);
    	}
    	for (h = 1, i = 0; i < k ; i++)
    	{
        		if (t[i] != c[i])
            		h = 0;
    	}
	if(h==1)
		printf("\nThe string is  palindrome");
	else
		printf("\nThe string is not a palindrome");	
}
