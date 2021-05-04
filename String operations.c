#include<stdio.h>
#include<string.h>
main()
{
	int i,j,k;
	char n[20],a[40];
	printf("Enter the name - ");
	gets(n);
	printf("Enter another name - ");
	gets(a);
	printf("Hello %s\n\t",n);
	puts(a);
	printf("\nLength of the string - %d",strlen(n));
	printf("\nString in lower case - %s",strlwr(n));
	printf("\nString in upper case - %s",strupr(n));
	printf("\nConcatenated string - %s",strcat(a,n));
	printf("\nConcatenated string limited - %s",strncat(a,n,4));
	printf("\ncopied string - %s",strcpy(a,n));
	printf("\nCopied string limited - %s",strncpy(a,n,3));
	printf("\nReversed string - %s",strrev(n));
	i=strcmp(a,n);
	j=strncmp(a,n,4);
	k=stricmp(a,n);
	printf("\nComarison of two strings - %d",i);
	printf("\nComparison of two strings limited - %d",j);
	printf("\nComparison of two strings ignoring case - %d",k);
	printf("\nDuplicated string - %s",strdup(n));
	printf("\nOccurrence of a character in the string %d",strchr(n,'a'));
	printf("\nLast occurrence of a character %d",strrchr(a,'a')); 
	printf("\nSubstring of the main string %s",strstr(n,a));
	printf("\nReplacing the characters %s",strset(a,'f'));
}
