#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "array.h"

array::array ( size_t row, size_t col ) 
    : row( row > 0 ? row : throw std::invalid_argument( "Row must be > 0" ) ),
      col( col > 0 ? col : throw std::invalid_argument( "Column must be > 0" ) )
{
    ptr = new double*[row];
    for (size_t i = 0; i < row; i++)
    {
        ptr[i] = new double[col];
        for (size_t j = 0; j < col; j++)
        {
            ptr[i][j] = 0.0;
        }
    }
}

array::array( const array &arr ) 
    : row( arr.row ),
      col( arr.col),
      ptr ( new double* [row] )
{
    for (size_t i = 0; i < row; i++)
    {
        ptr[i] = new double[col];
        for (size_t j = 0; j < col; j++)
        {
            ptr[i][j] = arr.ptr[i][j];
        }
        
    }
    
}

array::array(std::initializer_list<std::initializer_list<double>> list)
    :row(list.size())
{
    ptr = new double*[row];
    std::initializer_list < std::initializer_list <double>> ::iterator roww;
    std::initializer_list<double>::iterator coll;
    size_t i, j;
    
    for (roww = list.begin(), i = 0; roww != list.end(); ++i, roww++)
    {
        col = roww->size();
        ptr[i] = new double[col];
        for (coll = roww->begin(), j = 0; coll < roww->end(); ++j, coll++)
        {
            ptr[i][j] = *coll;
        }   
    }
}

array::~array() {
    for (size_t i = 0; i < row; i++)
    {
        delete []ptr[i];
    }
    delete []ptr;
}

double& array::operator()( size_t row, size_t col ) {

    if ( row < 0 && col < 0 ) {
        throw std::invalid_argument( "Dimensions must be positive " );
    } 
    return ptr[row][col];
}

std::ostream &operator<<(std::ostream &output, const array &arr) {
    for (size_t i = 0; i < arr.row; i++)
    {
        for (size_t j = 0; j < arr.col; j++)
        {
            std::cout << std::setw(2 * arr.col + 1) << arr.ptr[i][j];
        }
        output << std::endl;   
    }
    return output;
}

std::istream &operator>>( std::istream &input, array &a ) {
    //output private ptr-based array
    for (size_t i = 0; i < a.row; i++)
    {
        for (size_t j = 0; j < a.col; j++)
        {
            input >> a.ptr[i][j];
        }
    }
    return input;
}

const array& array::operator=( const array& right ) {
    
    if (this != &right) // preventing the operation if they're already the same.
    {
        
        if ((right.col != col))
        {
            for (size_t i = 0; i < col; i++)
            {
                delete []ptr[i];
            }
        }

        if (right.row != row)
        {
            delete []ptr;
        }
        
        row = right.row;
        col = right.col;

        ptr = new double*[row];

        for (size_t i = 0; i < row; i++)
        {
            ptr[i] = new double[col];
            for (size_t j = 0; j < col; j++)
            {
                ptr[i][j] = right.ptr[i][j];
            }
        }
    }
    
    return *this;

}

bool array::operator==(const array &arr) const {
    
    if((arr.col != col) || (arr.row != row)) // check the dims.
        return false;
    
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (ptr[i][j] != arr.ptr[i][j])
            {
                return false;
            }
        }
    }
    
    return true;
}

bool array::operator!=(const array& right) const{
    return !(*this == right);
}

size_t array::getSize() const {
    return row * col;
}

size_t array::getRow() const {
    return row;
}

size_t array::getColumn() const {
    return col;
}