#include <iostream>
#include "Employee.h"
#include "CommisionEmployee.h"
#include "BasePlusCommissionEmployee.h"


int main(int argc, char const *argv[])
{
    Employee emp("John", "Doe", "1234567890");
    CommisionEmployee cemp(emp, .1, 10000);
    BasePlusCommissionEmployee bpce( cemp, 1000);

    bpce.print();
 


    return 0;
}
