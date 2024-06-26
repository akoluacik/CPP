#ifndef NEWS_API_HANDLER
#define NEWS_API_HANDLER

#include "api_handler.h"

class News_Api_Handler : public Api_Handler
{
private:
    // TODO
    std::string query = "https://newsapi.org/v2/everything?q=";
    std::string params = "";
    std::string api_key = "&apiKey=b1b0bc94cc2f49189bd3dd2d5e110a13";
    std::string readBuffer;
public:
    News_Api_Handler();
    virtual ~News_Api_Handler();


    virtual void get_data(std::string request) override;
    virtual void print_data() const override;
    // virtual bool send_request(std::string request) override; // request here is the title of the news
};


#endif