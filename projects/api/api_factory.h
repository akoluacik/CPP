#ifndef API_FACTORY_H
#define API_FACTORY_H

#include "api_handler.h"
#include "weather_api_handler.h"
#include "news_api_handler.h"
#include <memory>

class Api_Factory {
public:
    static std::unique_ptr<Api_Handler> createApiClient(const std::string& type) {
        if (type == "weather")
            return std::make_unique<Weather_Api_Handler>();
        else if (type == "news")
            return std::make_unique<News_Api_Handler>();
        else
            return nullptr;
    }
};

#endif // API_FACTORY_H
