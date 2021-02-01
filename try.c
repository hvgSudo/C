#include<stdio.h>

struct try {
    int a;
    char b;
    float c;
}var;

union tyre {
    int d;
    char e;
    float f;
}var_1;

int main()
{
    var.a = 1;
    var_1.d = 5;
    printf("\nUnion: %d %c %lf", var_1.d, var_1.e, var_1.f);
    printf("Structure: %d %c %lf", var.a, var.b, var.c);
    return 0;
}