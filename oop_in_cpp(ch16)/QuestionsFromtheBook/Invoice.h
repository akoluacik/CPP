#include <string>

class Invoice
{
public:
    Invoice(std::string _partNumber, std::string _description
    , int amout, int _price);

    /* Mutators Start */
    void setPartNumber(std::string _partNumber);
    void setDescription(std::string _description);
    void setAmount(int _amount);
    void setPrice(int _price);
    /* Mutators End */

    /* Accessors Start */
    std::string getPartNumber();
    std::string getDescription();
    int getAmount();
    int getPrice();
    /* Accessors End */

    int getInvoiceAmount();
private:
    std::string partNumber;
    std::string description;
    int amount; // to be purchased
    int price; // price per item.
};