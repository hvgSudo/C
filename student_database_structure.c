#include<stdio.h>
#include<string.h>

struct student_database {
	char name[50];
	long long int prn;
	float percentage;
}s[30];

int i, m = 0;
char ch;

void display();

int create(int n) {
	for (i = 0; i < n; i++) {
		printf("\nStudent name: ");
		fflush(stdin);
		gets(s[i].name);
		fflush(stdin);
		printf("\nPRN: ");
		scanf("%lld", &s[i].prn);
		printf("\nPercentage: ");
		scanf("%f", &s[i].percentage);
		m++; 
	}
	return 1;
}

int add(int n) {
	for (i = m; i < m + n; i++) {
		printf("\nStudent name: ");
		fflush(stdin);
		gets(s[i].name);
		printf("\nPRN: ");
		scanf("%lld", &s[i].prn);
		printf("\nPercentage: ");
		scanf("%f", &s[i].percentage);
	}
	m = m + n;
	return 1;
}

int modify(long long int prn) {
	int choice;
	for (i = 0; i < m; i++) {
			if (prn == s[i].prn) {
			printf("\n1. Name");
			printf("\n2. PRN");
			printf("\n3. Percentage");
			printf("\n4. All of the above");
			printf("\nWhat do you want to modify: ");
			scanf("%d", &choice);
			switch (choice) {
			case 1:
				printf("\nEnter the name: ");
				fflush(stdin);
				gets(s[i].name);
				break;
			case 2:
				printf("\nEnter the PRN: ");
				scanf("%lld", &s[i].prn);
				break;
			case 3:
				printf("\nEnter the percentage: ");
				scanf("%f", &s[i].percentage);
				break;
			case 4:
				printf("\nEnter the name: ");
				fflush(stdin);
				gets(s[i].name);
				printf("\nEnter the PRN: ");
				scanf("%lld", &s[i].prn);
				printf("\nEnter the percentage: ");
				scanf("%f", &s[i].percentage);
				break;
			default:
				printf("Wrong choice");
			}
			return 1;
		}
	}
	return 0;
}

int delete (long long int prn) {
	int j;
	char name[50];
	for (i = 0; i < m; i++) {
		if (prn == s[i].prn) {
			for (j = i; j < m - 1; j++) {
				s[j].prn = s[j + 1].prn;
				s[j].percentage = s[j + 1].percentage;
				strcpy(s[j].name, s[j + 1].name);
			}
			m--;
			return 1;
		}
	}
	return 0;
}

int main() {
	int choice, how_many, ret;
	long long int prn;
	do {
		printf("\n1. Create the database");
		printf("\n2. Add new student");
		printf("\n3. Modify the database");
		printf("\n4. Delete from the database");
		printf("\n5. Display the database");
		printf("\n6. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("\nHow many students do you want to enter: ");
				scanf("%d", &how_many);
				ret = create(how_many);
				if (ret == 1)	
					printf("\nDatabase created");
				display();
				break;
			case 2:
				printf("\nHow many students do you want to enter: ");
				scanf("%d", &how_many);
				if (how_many <= 0) {
					printf("\n0 students inserted to the database");
					break;
				} 
				else
					ret = add(how_many);
				if (ret == 1 && how_many > 1) 
					printf("\nStudents added to the database");
				else
					printf("\nStudent entered");
				display();
				break;
			case 3: 
				printf("\nEnter the prn of the student you want to modify: ");
				scanf("%lld", &prn);
				ret = modify(prn);
				if (ret == 1) {
					printf("\nStudent data modified");
					display();
				}
				else
					printf("\nStudent data not found");
				break;
			case 4:
				printf("\nEnter the prn of the student you want to delete: ");
				scanf("%lld", &prn);
				ret = delete(prn);
				if (ret == 1)
					printf("\nStudent data deleted");
				else
					printf("\nStudent data not found");
				display();
				break;
			case 5:
				display();
				break;
			case 6:
				break;
			default:
				printf("\nWrong choice");
		}
		printf("\nDo you want to perform more operations(y/n): ");
		fflush(stdin);
		scanf("%c", &ch);
	}while(ch == 'y' || ch == 'Y');
	return 0;
}

void display() {
	printf("\n-------------------------------------------");
	printf("\nPRN\t\t");
	printf("Name\t\t");
	printf("Percentage\n");
	for (i = 0; i < m; i++) {
		printf("\n%lld \t %s \t %.2f", s[i].prn, s[i].name, s[i].percentage);
	}
	printf("\n------------------------------------------");
}