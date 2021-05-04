#include<stdio.h>

struct student {
    char name[30];
    long long int prn;
    char branch[20];
    int marks;
    char address[50];
}s[7];

int i;

int main() {
    for (i = 0; i < 5; i++) {
        printf("\nStudent %d", i + 1);
        printf("\nName: ");
        fflush(stdin);
        scanf("%[^\n]%*c", &s[i].name);
        printf("PRN: ");
        scanf("%lld", &s[i].prn);
        printf("Branch: ");
        fflush(stdin);
        scanf("%[^\n]%*c", &s[i].branch);
        printf("Marks: ");
        scanf("%d", &s[i].marks);
        printf("Address: ");
        fflush(stdin);
        scanf("%[^\n]%*c", &s[i].address);
    }    
    printf("\nDetails of the students are: \n");
    for (i = 0; i < 5; i++) {
        printf("\n\nStudent %d", i + 1);
        fflush(stdin);
        printf("\nName: %s", s[i].name);
        printf("\nPRN: %lld", s[i].prn);
        fflush(stdin);
        printf("\nBranch: %s", s[i].branch);
        printf("\nMarks: %d", s[i].marks);
        fflush(stdin);
        printf("\nAddress: %s", s[i].address);
    }
    return 0;
}