#include<conio.h>
#include<stdio.h>
int main() {
    int choice, ans;
    do {
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                   printf("I am in case 1\n");
                   break;
            case 2:
                   printf("I am in case 2\n");
                   break;
            default:
                   printf("I am in default\n");
        }
        printf("Run again 1-yes 0-no: ");
        scanf("%d", &ans);
    }while(ans != 0);
}