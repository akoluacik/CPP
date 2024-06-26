#ifndef API_HANDLER_H
#define API_HANDLER_H

#include <string>

class Api_Handler
{
private:
    // std::string json_data;
    // std::string query = "";
    // std::string api_key = "";

public:
    Api_Handler();
    virtual ~Api_Handler();

    virtual bool send_request(std::string query, std::string api_key, std::string params, std::string request, std::string* read_buffer);
    virtual void get_data(std::string request) = 0;
    virtual void print_data() const = 0;
};


#endif