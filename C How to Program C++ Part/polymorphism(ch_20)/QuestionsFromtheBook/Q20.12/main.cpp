#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

int main(int argc, char const *argv[])
{
    Date date1(9, 15, 1964), date2(2, 14, 1999), date3(2, 1, 1991);

    // set floating-point output formatting
    std::cout << std::fixed << std::setprecision( 2 );
    
    // create vector of three base-class pointers
    std::vector < Employee * > employees( 3 );

    // initialize vector with various kinds of Employees
    employees[0] = new SalariedEmployee( "John" , "Smith", "111-11-1111", date1, 80);
    employees[1] = new CommissionEmployee( "Sue" , "Jones", "333-33-3333", date2, 10000, 0.6);
    employees[2] = new BasePlusCommissionEmployee( "Bob" , "Lewis", "444-55-5554", date3, 5000, 0.4, 300);

    // polymorphically process each element in vector employees
    for (Employee *employeePtr : employees) {
        employeePtr -> print(); // output employee infor
        std::cout << std::endl;

        // attempt to downcast pointer
        BasePlusCommissionEmployee *derivedPtr = 
            dynamic_cast < BasePlusCommissionEmployee * >( employeePtr );

        // determine whether element points to a BasePlusCommissionEmployee
        if ( derivedPtr != nullptr )
        {
            double oldBaseSalary = derivedPtr->getBaseSalary();
            std::cout << "old base salary: $" << oldBaseSalary << std::endl;
            derivedPtr->setBaseSalary( 1.10 * oldBaseSalary );
            std::cout << "New base salary with 10% is: $" << derivedPtr->getBaseSalary() << std::endl;
        }
        
        std::cout << "earned $" << employeePtr->earnings() << "\n\n";
    }


    for (const Employee *employeePtr : employees) {
        std::cout << "deleting object of " << typeid( *employeePtr ).name() << std::endl;
        delete employeePtr;
    }

    return 0;
}
