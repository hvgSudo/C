#include<stdio.h>
struct employee
	{
		int id;
		char name[30];
		char desig[20];
		char dept[20];
		float salary;
	}e;
void emp(struct employee);
main()
{
	printf("Enter the details of the employee");
	printf("\nID Number - ");
	scanf("%d",&e.id);
	fflush(stdin);
	printf("Name - ");
	gets(e.name);
	fflush(stdin);
	printf("Designation - ");
	gets(e.desig);
	fflush(stdin);
	printf("Department - ");
	gets(e.dept);
	fflush(stdin);
	printf("Salary - ");
	scanf("%f",&e.salary);
	printf("\n\tPay Slip of the employee");
	emp(e);
}
void emp(struct employee m)
{
	printf("\nID Number - %d",m.id); 
	printf("\nName - %s",m.name);
	printf("\nDesignation - %s",m.desig);
	printf("\nDepartment - %s",m.dept);
	printf("\nSalary - %f",m.salary);
}
	
