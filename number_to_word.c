#include<stdio.h>

void cber_to_word(int, char*);

void main() {
    char c[10];
    int n;
    printf("Enter the length of the number: ");
    scanf("%d", &n);
    printf("Enter the cber: ");
    fflush(stdin);
    gets(c);
    cber_to_word(n, c);
}

void cber_to_word(int n, char *c) {
    if (n == 0) {
        printf("empty string\n");
        return;
    }
    if (n > 4) {
        printf("length more than 4 is not supported\n");
        return;
    }

    char *single_digits[] = {"zero", "one", "two",
                             "three", "four", "five",
                             "six", "seven", "eight", "nine"};
    char *two_digits[] = {"", "ten", "eleven", "twelve",
                          "thirteen", "fourteen",
                          "fifteen", "sixteen",
                          "seventeen", "eighteen", "nineteen"};
    char *tens_multiple[] = {"", "", "twenty", "thirty", "forty", "fifty",
                             "sixty", "seventy", "eighty", "ninety"};

    char *tens_power[] = {"hundred", "thousand"};

    printf("\n%s: ", c);
    if (n == 1) {
        printf("%s\n", single_digits[*c - '0']);
        return;
    }

    while (*c != '\0') {
        if (n >= 3) {
            if (*c - '0' != 0) {
                printf("%s ", single_digits[*c - '0']);
                printf("%s ", tens_power[n - 3]);
            }
            --n;
        }
        else {
            if (*c == '1') {
                int sum = *c - '0' + *(c + 1) - '0';
                printf("%s\n", two_digits[sum]);
                return;
            }
            else if (*c == '2' && *(c + 1) == '0') {
                printf("twenty\n");
                return;
            }
            else {
                int i = *c - '0';
                printf("%s ", i ? tens_multiple[i] : "");
                ++c;
                if (*c != '0')
                    printf("%s ", single_digits[*c - '0']);
            }
        }
        ++c;
    }
}