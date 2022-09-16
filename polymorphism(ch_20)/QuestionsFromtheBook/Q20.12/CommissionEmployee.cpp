// Fig. 12.14: CommissionEmployee.cpp
// CommissionEmployee class member-function definitions.
#include <iostream>
#include <stdexcept>
#include "CommissionEmployee.h" // CommissionEmployee class definition

// constructor 
CommissionEmployee::CommissionEmployee( const std::string &first, 
   const std::string &last, const std::string &ssn, Date& date, double sales, double rate )
   : Employee( first, last, ssn, date )  
{
   setGrossSales( sales );
   setCommissionRate( rate );
} // end CommissionEmployee constructor

// set commission rate
void CommissionEmployee::setCommissionRate( double rate )
{ 
   if ( rate > 0.0 && rate < 1.0 )
      commissionRate = rate;
   else
      throw std::invalid_argument( "Commission rate must be > 0.0 and < 1.0" );
} // end function setCommissionRate

// return commission rate
double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
} // end function getCommissionRate

// set gross sales amount
void CommissionEmployee::setGrossSales( double sales ) 
{ 
   if ( sales >= 0.0 )
      grossSales = sales;
   else
      throw std::invalid_argument( "Gross sales must be >= 0.0" );
} // end function setGrossSales

// return gross sales amount
double CommissionEmployee::getGrossSales() const
{
    return grossSales;
} // end function getGrossSales

// calculate earnings; override pure virtual function earnings in Employee
double CommissionEmployee::earnings() const
{
   double res = getCommissionRate() * getGrossSales();
   if( Employee::getCurrentMonth() == Employee::getBirthDate().getMonth() )
      res += 100;
   return res;
} // end function earnings

// print CommissionEmployee's information 
void CommissionEmployee::print() const
{
   std::cout << "commission employee: ";
   Employee::print(); // code reuse
   std::cout << "\ngross sales: " << getGrossSales() 
      << "; commission rate: " << getCommissionRate();
} // end function print
