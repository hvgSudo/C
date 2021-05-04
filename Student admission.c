#include<stdio.h>
main()
{
	int age,score,pcm;
	printf("Enter the age - ");
	scanf("%d",&age);
	printf("\nEnter the score - ");
	scanf("%d",&score);
	printf("\nEnter the pcm score - ");
	scanf("%d",&pcm);
	if((age>=17)&&(pcm>70)||(score>80))
	{
		printf("\nStudent is eligible for admission");
	}
	else
	{
		printf("\nStuddent is not eligible for admission");
	}
}
