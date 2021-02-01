#include<stdio.h>

void octal(int);
void hex(int);
void bin(int);

int main() {
	int a;
	char c;
	do {
		printf("Enter the number: ");
		scanf("%d", &a);
		octal(a);
		printf("\nDo you want to convert more numbers(y/n): ");
		scanf("%c", &c);
		scanf("\n");
	}while(c == 'y' || c == 'Y');
	return 0;
}

void octal(int a) {
	int oct = a, i = 0, j;
	int d[10];
	printf("Number in decimal number system: %d", a);
	while (oct != 0) {
		d[i] = oct % 8;
		oct = oct / 8;
		i++;
	}
	printf("\nNumber in octal number system: ");
	for (j = i - 1; j >= 0; j--)
		printf("%d", d[j]);
}

void hex(int a) {
	int k = 0, hex = a, temp, j;
	char b[10];
	while (hex != 0) {
		temp = 0;
		temp = hex % 16;
		if (temp < 10) {
			b[k] = 48 + temp; // ASCII value of the character gets stored in the array
			k++;
		} else {
			b[k] = 55 + temp; // ASCII value gets stored in the array
			k++;
		}	
		hex = hex / 16;
	}
	printf("\nNumber in hexadecimal number system: ");
	for (j = k - 1; j >= 0; j--) {
		printf("%d", b[j]);
	}
}

void bin(int a) {
	int bin = a, l = 0, c[10], j;
	while (bin != 0) {
		c[l] = bin % 2;
		bin = bin / 2;
		l++;
	}
	printf("\nNumber in binary number system: ");
	for (j = l - 1; j >= 0; j--)
		printf("%d", c[j]);
}
