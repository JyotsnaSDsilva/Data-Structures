#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

#include "emp.h"

int main()
{
    EmpD *test;

    test = initialize_array_d(10);


    insert_data(test, "john", "Architecture", 56,550.00);
    insert_data(test, "alex", "Developing", 58,550.00);

    return 0;
}
