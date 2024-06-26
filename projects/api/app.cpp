#include "app.h"

void App::setApiClient(std::unique_ptr<Api_Handler>& client) {
    apiClient = std::move(client);
    client = nullptr;
}
void App::display(std::string request) {
    if (apiClient) {
        apiClient->get_data(request);
        apiClient->print_data();
    } else {
        std::cerr << "API Client is not set!" << std::endl;
    }
}