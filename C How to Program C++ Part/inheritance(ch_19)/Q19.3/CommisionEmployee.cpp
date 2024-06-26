#include "CommisionEmployee.h"
#include <stdexcept>


CommisionEmployee::CommisionEmployee( Employee emp, double rate, double sales )
    : emp(emp),
      grossSales(sales),
      commissionRate(rate)
{
    // empty ctor body
}
void CommisionEmployee::setCommissionRate ( const double rate ) {
    if(rate >= 0)
        commissionRate = rate;
    else
        throw std::invalid_argument( "Rate must be >= 0" );
}

double CommisionEmployee::getCommissionRate() const {
    return commissionRate;
}

Employee CommisionEmployee::getEmployee() const {
    return emp;
}

void CommisionEmployee::setGrossSales ( const double sales ) {
    if( sales >= 0 ) 
        grossSales = sales;
    else
        throw std::invalid_argument( "Sales must be >= 0!");
}

double CommisionEmployee::getGrossSales() const {
    return grossSales;
}