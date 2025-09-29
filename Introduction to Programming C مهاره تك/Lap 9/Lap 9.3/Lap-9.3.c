#include <stdio.h>

typedef struct Employee
{
    float salary;
    int bonus;
    int deduction;
} Emp;


int main()
{
    Emp ahmed;
    Emp amr;
    Emp waleed;
	int Salary , Bonus , Deduction;
	
	printf("Please Enter Ahmed's Salary : ");
	scanf("%f", &(ahmed.salary));
	
	printf("Please Enter Ahmed's Bonus : ");
	scanf("%d", &(ahmed.bonus));
	
	printf("Please Enter Ahmed's Deduction : ");
	scanf("%d", &(ahmed.deduction));
	
	printf("Please Enter Amr's Salary : ");
	scanf("%f", &(amr.salary));
	
	printf("Please Enter Amr's Bonus : ");
	scanf("%d", &(amr.bonus));
	
	printf("Please Enter Amr's Deduction : ");
	scanf("%d", &(amr.deduction));
	
	printf("Please Enter Waleed's Salary : ");
	scanf("%f", &(waleed.salary));
	
	printf("Please Enter Waleed's Bonus : ");
	scanf("%d", &(waleed.bonus));
	
	printf("Please Enter Waleed's Deduction : ");
	scanf("%d", &(waleed.deduction));

    Salary = (ahmed.salary) + (amr.salary) + (waleed.salary) ;
	Bonus = (ahmed.bonus) + (amr.bonus) + (waleed.bonus) ;
	Deduction = (ahmed.deduction) + (amr.deduction) + (waleed.deduction) ;
	
	printf("Total Value Needed is %d " , (Salary+Bonus-Deduction));

    return 0;
}

