
#include<stdlib.h>
#include<stdio.h>
#include "emp.h"

EmpD *initialize_arr_d(int size) //initialization of array
{
    EmpD *emp_array;

    emp_array = (EmpD *)malloc(sizeof(EmpD));

    emp_array->c_size = 0;
    emp_array->t_size = size;

    emp_array->emp  = (int *)malloc(sizeof(int) * size);

    emp_array->emp->salary = 0.0;
    emp_array->emp->empID = c_size + 1;                          //ID is index


    return emp_array;
}

int insert_data(EmpD *emp_array, char name[], char department[], float salary) //inserts data
{
    if(emp_array->c_size == emp_array->t_size)
        return 0;

    emp_array->emp->name[emp_array->c_size] =  name;
    emp_array->emp->department[emp_array->c_size] =  department;
    emp_array->emp->salary[emp_array->c_size] =  salary;
    c_size++;


    return 1;

}

int search(EmpD *emp_array, int id)         //searches by employee ID
{
    int i;

    for(i=0; i<emp_array->c_size;i++)
    {
        if(emp_array->emp->empID[i] == id)
            return 1;
    }
    return 0;
}

void display(EmpD * emp_array) //displays data
{
    int i;

    for(i = 0; i < emp_array->c_size; i++)
    {
        printf("%d ",emp_array->emp->empID[i]);
        puts(emp_array->emp->name);
        printf("%d ",emp_array->emp->salary[i]);
        puts(emp_array->emp->department);
    }

}
