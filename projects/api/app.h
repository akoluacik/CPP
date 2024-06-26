#ifndef APP_H
#define APP_H

#include "api_handler.h"
#include <memory>
#include <iostream>

class App {
private:
    std::unique_ptr<Api_Handler> apiClient;

public:
    void setApiClient(std::unique_ptr<Api_Handler>& client);
    void display(std::string request);
};

#endif