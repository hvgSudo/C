#include<stdio.h> 
#include<math.h>
#include<string.h>

void decimal(int);
void octal(int);
void hexadecimal(char[]);
void binary(int);
int j;
int main() {
	int choice, number, n;
	char cha, num[10];
	do {
        printf("\nOnly whole numbers can be used");
		printf("\n1. Decimal number");
		printf("\n2. Octal number");
		printf("\n3. Hexadecimal number");
		printf("\n4. Binary number");
		printf("\nWhich type of number do you want to enter: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("\nEnter the decimal number: ");
                scanf("%d", &number);
                if (number < 0) {
                    printf("\nOnly whole numbers can be used");
                    break;
				}
				decimal(number);
				break;
			case 2:
                printf("\nEnter the octal number: ");
                scanf("%d", &number);
                if (number < 0) {
					printf("\nOnly whole numbers can be used");
					break;
				}
				octal(number);
				break;
			case 3:
                printf("\nEnter the hexadecimal number: ");
                fflush(stdin);
				gets(num);
				hexadecimal(num);
				break;
			case 4:
				printf("\nEnter the binary number: ");
                scanf("%d", &number);
                if (number < 0) {
					printf("\nOnly whole numbers can be used");
					break;
				}
				binary(number);
				break;
			default:
				printf("\nWrong choice");
		}
		printf("\nDo you want to convert more numbers(y/n): ");
		fflush(stdin);
        scanf("%c", &cha);
	}while(cha == 'y' || cha == 'Y');
	return 0;
}

void decimal(int number) {
	int oct = number, hex = number, bin = number;
	int i = 0, l = 0, k = 0, temp = 0;
	char d[10], b[10], c[10];
	
	// decimal to octal
	while (oct != 0) {
		temp = 0;
		temp = oct % 8;
		d[i] = 48 + temp; // ASCII value gets stored in the array
		i++;
		oct = oct / 8;
	}
	printf("\nNumber in octal number system: ");
	for (j = i - 1; j >= 0; j--) 
		printf("%c", d[j]);
		
	// decimal to hexadecimal
	while (hex != 0) {
		temp = 0;
		temp = hex % 16;
		if (temp < 10) {
			c[k] = 48 + temp; // ASCII value gets stored in the array
			k++;
		} else {
			c[k] = 55 + temp; // ASCII value gets stored in the array
			k++;
		}	
		hex = hex / 16;
	}
	printf("\nNumber in hexadecimal number system: ");
	for (j = k - 1; j >= 0; j--) 
		printf("%c", c[j]);
		
	// decimal to binary
	while (bin != 0) {
		temp = 0;
		temp = bin % 2;
		b[l] = 48 + temp; // ASCII value gets stored in the array
		l++;
		bin = bin / 2;
	}
	printf("\nNumber in binary number system: ");
	for (j = l - 1; j >= 0; j--) 
		printf("%c", b[j]);
}

void octal(int number) {
	int dec = number, hex, bin;
	int i = 0, l = 0, k = 0;
	int temp = 0, tem = 0, te = 0;
	int d[10];
	char c[10], b[10];
	
	// octal to decimal
	while (dec != 0) {
		d[i] = dec % 10;
		dec = dec / 10;
		i++;
	}
	for (j = 0; j < i; j++) 
		temp = temp + d[j] * pow(8, j);
	printf("\nNumber in decimal number system: %d", temp);
	
	// octal to binary
	bin = temp;
	while (bin != 0) {
		tem = 0;
		tem = bin % 2;
		b[l] = 48 + tem; // ASCII value gets stored in the array
		l++;
		bin = bin / 2;
	}
	printf("\nNumber in binary number system: ");
	for (j = l - 1; j >= 0; j--) 
		printf("%c", b[j]);
		
	// octal to hexadecimal
	hex = temp;
	while (hex != 0) {
		te = 0;
		te = hex % 16;
		if (te < 10) {
			c[k] = 48 + te; // ASCII value gets stored in the array
			k++;
		} else {
			c[k] = 55 + te; // ASCII value gets stored in the array
			k++;
		}	
		hex = hex / 16;
	}
	printf("\nNumber in hexadecimal number system: ");
	for (j = k - 1; j >= 0; j--) 
		printf("%c", c[j]);
}

void hexadecimal(char num[]) {
	int oct, bin, j, len = strlen(num);
	int i = 0, l = 0, k = 0, base = 1;
	int temp = 0, tem = 0, te = 0, t = 0;
	char c[10], b[10], a[10];
	
	// hexadecimal to decimal
	for (j = len - 1; j >= 0; j--) {
		if (num[j] >= '0' && num[j] <= '9') {
			temp += (num[j] - 48) * base;
			base = base * 16;
		} else if (num[j] >= 'A' && num[j] <= 'F') {
			temp += (num[j] - 55) * base;
			base = base * 16; 
		}
	}
    printf("\nNumber in decimal number system: %d", temp);
            
    // hexadecimal to octal
    oct = temp;
    while (oct != 0) {
        te = 0;
        te = oct % 8;
        a[i] = 48 + te; // ASCII value gets stored in the array
        i++;
        oct = oct / 8;
    }
    printf("\nNumber in octal number system: ");
    for (j = i - 1; j >= 0; j--) 
        printf("%c", a[j]);
            
    // hexadecimal to binary
    bin = temp;
    while (bin != 0) {
        tem = 0;
        tem = bin % 2;
        b[l] = 48 + tem; // ASCII value gets stored in the array
        l++;
        bin = bin / 2;
    }
    printf("\nNumber in binary number system: ");
    for (j = l - 1; j >= 0; j--) 
        printf("%c", b[j]);
}

void binary(int number) {
	int dec = number, hex, oct;
	int i = 0, l = 0, k = 0;
	int temp = 0, tem = 0, te = 0;
	int d[10];
	char c[10], b[10];
	
	// binary to decimal
	while (dec != 0) {
		d[i] = dec % 10;
		dec = dec / 10;
		i++;
	}
	for (j = 0; j < i; j++) 
		temp = temp + d[j] * pow(2, j);
	printf("\nNumber in decimal number system: %d", temp);
	
	// binary to octal
	oct = temp;
	while (oct != 0) {
		tem = 0;
		tem = oct % 8;
		b[l] = 48 + tem; // ASCII value gets stored in the array
		l++;
		oct = oct / 8;
	}
	printf("\nNumber in octal number system: ");
	for (j = l - 1; j >= 0; j--) 
		printf("%c", b[j]);
		
	// binary to hexadecimal
	hex = temp;
	while (hex != 0) {
		te = 0;
		te = hex % 16;
		if (te < 10) {
			c[k] = 48 + te; // ASCII value gets stored in the array
			k++;
		} else {
			c[k] = 55 + te; // ASCII value gets stored in the array
			k++;
		}	
		hex = hex / 16;
	}
	printf("\nNumber in hexadecimal number system: ");
	for (j = k - 1; j >= 0; j--) 
		printf("%c", c[j]);
}
