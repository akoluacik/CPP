#include <iostream>
#include "weather_api_handler.h"
#include "news_api_handler.h"
#include "app.h"
#include "api_factory.h"

int main(int argc, char **argv) {
    
    std::string request;
    std::string app_choice;
    // Api_Handler *app;
    // Weather_Api_Handler wah;

    // if (argc == 1) {
    //     request = "Turgutlu";
    // } else {
    //     request = std::string(argv[1]);
    // }

    // wah.get_data(city);
    // wah.print_data();
    
    // News_Api_Handler nah;

    // nah.get_data(request);
    // nah.print_data();   

    App app;
    if (argc < 3) {
        app_choice = "weather";
        request = "Turgutlu";
    } else {
        app_choice = std::string(argv[1]);
        request = std::string(argv[2]);
    }

    auto apiClient = Api_Factory::createApiClient(app_choice);
    app.setApiClient(apiClient);
    app.display(request);
}