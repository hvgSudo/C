#include<stdio.h>

void number_in_words(int, int);

void main() {
    int n, num;
    //char num[10];
    printf("Enter the length of the number(upto 4): ");
    scanf("%d", &n);
    printf("Enter the number: ");
    scanf("%d", &num);
    number_in_words(n, num);
}

void number_in_words(int n, int num) {
    int i, current, a[7], b[10], c[4], digit;
    current = num;
    char single[12][12] = {"zero", "one", "two", "three", "four",
                        "five", "six", "seven", "eight", "nine"};
    char teen[10][10] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen",
                         "sixteen", "seventeen", "eighteen", "nineteen"};
    char ty[10][10] = {"twenty", "thirty", "forty", "fifty", "sixty",
                        "seventy", "eighty", "ninety"}; 
    if (n == 3) {
        digit = 100;
        for (i = 0; i < n; i++) {
            a[i] = num / digit;
            num = num % digit;
            digit = digit / 10;
        }
        for (i = 0; i < n; i++) {
            if (i == 0)
                printf("%s hundred ", single[a[i]]);
            else if (i == 1) {
                if (a[i] == 1) {
                    fflush(stdin);
                    printf("%s ", teen[a[i] + 1]);
                } else if ((a[i] == 1) && (a[i + 1] == 0)) {
                    fflush(stdin);
                    printf("ten");
                } else {
                    fflush(stdin);
                    printf("%s %s", ty[a[i] - 2], single[a[i + 1]]);
                }
            } 
        }
    } else if (n == 4) {
        digit = 1000;
        for (i = 0; i < n; i++) {
            b[i] = num / digit;
            num = num % digit;
            digit = digit / 10;
        }
        for (i = 0; i < n; i++) {
            if (i == 0)
                printf("%s thousand ", single[b[i]]);
            else if (i == 1) {
                fflush(stdin);
                printf("%s hundred ", single[b[i]]);
            }
            else if (i == 2) {
                if (b[i] == 1) {
                    fflush(stdin);
                    printf("%s ", teen[b[i] + 1]);
                }
                else if ((b[i] == 1) && (b[i + 1] == 0)) {
                    fflush(stdin);
                    printf("ten");
                }
                else {
                    fflush(stdin);
                    printf("%s %s", ty[b[i] - 2], single[b[i + 1]]);
                }
            }
        }
    } else if (n == 2) {
        digit = 10;
        for (i = 0; i < n; i++) {
            c[i] = num / digit;
            num = num % digit;
            digit = digit / 10;
        }
        for (i = 0; i < n; i++) {
            if (i == 0) {
                if (c[i] == 1 && c[i + 1] == 0) 
                    printf("ten");
                else if (c[i] == 1) {
                    fflush(stdin);
                    printf("%s", teen[c[i] + 1]);
                } else {
                    fflush(stdin);
                    printf("%s %s", ty[c[i] - 2], single[c[i + 1]]);
                }
            }
        }
    } else if (n == 1) {
        printf("%s", single[current]);
    }
}