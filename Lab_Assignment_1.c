#include<stdio.h>

int sum_of_digits(int, int);
int reverse_of_number(int, int);
int average_of_number(int, int*);
void triangular_number(int);
void number_in_words(int, int);

int i = 0;

void main() {
    int choice, n, number;
    int array[20];
    char c;
    do {
        printf("\n1. Sum of digits of a number");
        printf("\n2. Reverse of a number");
        printf("\n3. Average of n numbers");
        printf("\n4. Generate Triangular numbers");
        printf("\n5. Number in words");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                    printf("\nEnter the length of the number(upto 5): ");
                    scanf("%d", &n);
                    if (n > 5) {
                        printf("Length greater than 5 not supported");
                        break;
                    }
                    printf("Enter the number: ");
                    scanf("%d", &number);
                    printf("\nSum of digits of the number %d: %d", number, sum_of_digits(n, number));
                    break;
            case 2:
                    printf("\nEnter the length of the number(upto 5): ");
                    scanf("%d", &n);
                    if (n > 5)
                    {
                        printf("Length greater than 5 not supported");
                        break;
                    }
                    printf("Enter the number: ");
                    scanf("%d", &number);
                    printf("\nReverse of the number %d: %d", number, reverse_of_number(n, number));
                    break;
            case 3:
                    printf("\nEnter the number of inputs(upto 20): ");
                    scanf("%d", &n);
                    if (n > 20)
                    {
                        printf("Length greater than 20 not supported");
                        break;
                    }
                    printf("Enter the elements: ");
                    for (i = 0; i < n; i++) {
                        scanf("%d", &array[i]);
                    }
                    printf("\nThe average of the given numbers: %d", average_of_number(n, array));
                    break;
            case 4:
                    printf("\nHow many numbers do you want to generate(upto 20): ");
                    scanf("%d", &n);
                    if (n > 20)
                    {
                        printf("Length greater than 20 not supported");
                        break;
                    }
                    triangular_number(n);
                    break;
            case 5:
                    printf("\nEnter the length of the number(upto 4): ");
                    scanf("%d", &n);
                    if (n > 4)
                    {
                        printf("Length greater than 4 not supported");
                        break;
                    }
                    printf("Enter the number: ");
                    scanf("%d", &number);
                    printf("\n%d: ", number);
                    number_in_words(n, number);
                    break;
            default:
                    printf("Wrong choice");
        }
        printf("\nDo you want to perform more operations(y/n): ");
        fflush(stdin);
        scanf("%c", &c);
    }while((c == 'y') || (c == 'Y'));
}

int sum_of_digits(int n, int number) {
    int r = 0, rn = 0, sum = 0;
    for (i = 0; i < n; i++) {
        r = number % 10;
        sum = sum + r;
        number = number / 10;
    }
    return(sum);
}

int reverse_of_number(int n, int number) {
    int r = 0, rn = 0;
    for (i = 0; i < n; i++) { // n = 3
        r = number % 10; //  1 % 10 = 1 
        rn = rn * 10 + r; // 32 * 10 + 1 = 321
        number = number / 10; // 1 / 10 = 0
    }
    return(rn);
}

int average_of_number(int n, int *ptr) {
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum = sum + *ptr;
        ptr++; 
    }
    return(sum / n);
}

void triangular_number(int n) {
    int x = 0;
    printf("Triangular numbers upto %d are ", n);
    for (i = 1; i <= n; i++) {
        printf(" %d ", i + x); 
        x += i;
    }
}

void number_in_words(int n, int num) {
    int current, a[7], b[10], c[4], digit;
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
                }
                else if ((a[i] == 1) && (a[i + 1] == 0)) {
                    fflush(stdin);
                    printf("ten");
                }
                else { 
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
                }
                else {
                    fflush(stdin);
                    printf("%s %s", ty[c[i] - 2], single[c[i + 1]]);
                }
            }
        }
    } else if (n == 1) {
        printf("%s", single[current]);
    } else if (n > 4) {
        printf("\nEnter a number with less than 5 characters");
    }
}