#ifndef WEATHER_API_HANDLER
#define WEATHER_API_HANDLER

#include "api_handler.h"

class Weather_Api_Handler : public Api_Handler
{
private:
    
    std::string query = "https://api.openweathermap.org/data/2.5/weather?q=";
    std::string api_key = "4ee99b8f42e14e10abadf929595cb0b3";
    std::string params = "&appid=";
    std::string readBuffer;
public:
    Weather_Api_Handler();
    virtual ~Weather_Api_Handler();

    virtual void get_data(std::string request) override;
    virtual void print_data() const override;
    // virtual bool send_request(std::string request) = 0; // request here is the name of the city
};



#endif