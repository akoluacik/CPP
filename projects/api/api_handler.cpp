#include "api_handler.h"
#include <curl/curl.h>

// CURL write callback function
size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

Api_Handler::Api_Handler() { }
Api_Handler::~Api_Handler() { }

bool Api_Handler::send_request(std::string query, std::string api_key, std::string params, std::string request, std::string *read_buffer) {
    CURL* curl;
    CURLcode res;
    std::string link = query + request + params + api_key;
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        // std::cout << "CURL is initiated!" << std::endl;

        curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "UserAgent");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, read_buffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res != CURLE_OK)
            return false;
        return true;
    }
    return false;
}
