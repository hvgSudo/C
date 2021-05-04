#include<stdio.h> 

#include<stdlib.h> 

 

char rev[20]; 

int count = 0; 

 

void push(char str[]) { 

int i;  

rev[count] = str[i]; 

count = count + 1;  

} 

 

void pop() { 

while (count >= 0) { 
fflush(stdin);
printf("%s", rev[count - 1]); 

count = count - 1; 

} 

} 

 

int main() { 

int n, i; 

char s[20]; 

printf("\nEnter the length of the string: "); 

scanf("%d", &n); 

printf("\nEnter the string: "); 

scanf("%s", &s);
for ( i = 0; i < n; i++)
    push(s); 

pop(); 

return 0; 

} 
