//gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void){
    //definced in employeeOne.c or employeeTwo.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, long salaryToFind);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; 
   
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
  
   

    //Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else    
        printf("Employee is NOT found in the record\n");

    //Example found
    
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");

    if (matchPtr != NULL)
        printf("Employee name is in record %d\n", matchPtr - EmployeeTable);
    else    
        printf("Employee is NOT found in the record\n");

    
    //Example phone found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134");

    if (matchPtr != NULL)
        printf("Employee phone 909-555-2134 number is in record %d\n", matchPtr - EmployeeTable);
    else    
        printf("Employee phone is NOT found in the record\n");


    //Example phone not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "bob");
    if (matchPtr != NULL)
        printf("Employee phone 909-555-2134 number is in record %d\n", matchPtr - EmployeeTable);
    else    
        printf("Employee phone is NOT found in the record\n");

    //Example salary found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34);
    if (matchPtr != NULL)
        printf("Employee salary 6.34 is in record %d\n", matchPtr - EmployeeTable);
    else    
        printf("Employee salary is NOT found in the record\n");

    //Example salary found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 18.54);
    if (matchPtr != NULL)
        printf("Employee salary 6.34 is in record %d\n", matchPtr - EmployeeTable);
    else    
        printf("Employee salary is NOT found in the record\n");

    

    return EXIT_SUCCESS;
}