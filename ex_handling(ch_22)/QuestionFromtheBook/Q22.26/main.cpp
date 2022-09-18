#include <iostream>


int main(int argc, char const *argv[])
{
    
    try
    {
        // Uncomment to see which exception you want.
        /*throw (double)10.0;
        throw 10;
        throw 's';*/
        throw "other types";
    }
    catch(int c)
    {
        std::cout << "Int exception\n";
    }
    catch(char s)
    {
        std::cout << "char exception\n";
    }
    catch(double k)
    {
        std::cout << "double exception\n";
    }
    catch(...)
    {
        std::cout << "Caught other types!";
    }

    


    return 0;
}
