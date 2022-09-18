#if !defined(__INV_MEM_ACC)
#define __INV_MEM_ACC

#include <stdexcept>

class InvalidMemoryAccess : public std::out_of_range
{
public:
    InvalidMemoryAccess(/* args */) : std::out_of_range("Attempt to reach invalid beyond of the memory block!") {}
    //~InvalidMemoryAccess() {}
};

#endif // __INV_MEM_ACC


