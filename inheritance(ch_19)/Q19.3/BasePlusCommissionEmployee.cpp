#include "BasePlusCommissionEmployee.h"
#include <stdexcept>
#include <iostream>

BasePlusCommissionEmployee::BasePlusCommissionEmployee( CommisionEmployee come, double baseSalary)
    
    :come(come),
     baseSalary(baseSalary)
{

}

void BasePlusCommissionEmployee::setBaseSalary( double salary )
{
   if ( salary >= 0.0 )                                        
      baseSalary = salary;                                     
   else                                                        
      throw std::invalid_argument( "Salary must be >= 0.0" );       
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
   return baseSalary;
} 

double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + ( come.getGrossSales() * come.getCommissionRate() );
}

void BasePlusCommissionEmployee::print() const {
    std::cout << "base-salaried commission employee: " << come.getEmployee().getFirstName() << ' ' 
      << come.getEmployee().getLastName() << "\nsocial security number: " << come.getEmployee().getSocialSecurityNumber() 
      << "\ngross sales: " << come.getGrossSales() 
      << "\ncommission rate: " << come.getCommissionRate() 
      << "\nbase salary: " << baseSalary
      << "\n\nEmployee's earnings: $" << earnings() << std::endl;
      
}