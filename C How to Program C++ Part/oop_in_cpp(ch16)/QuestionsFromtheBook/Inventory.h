#include <string>

class Inventory
{
public:
    explicit Inventory(std::string _productName);
    
    int getStock() const;
    void Purchase();
    void Sale();


private:
    int stock = 0;
    std::string productName;
};