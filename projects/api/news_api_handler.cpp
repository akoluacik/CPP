#include "news_api_handler.h"
#include <nlohmann/json.hpp>
#include <list>
#include <iostream>

using json = nlohmann::json;

class news
{
private:
    std::string author;
    std::string title;
    std::string description;
public:
    news();
    news(/*std::string author, */std::string title,std::string description);
    ~news();
    // void set_author(std::string author);
    void set_title(std::string title);
    void set_description(std::string description);
    // void fill_news(std::string author, std::string title, std::string desc);

    // std::string get_author() const;
    std::string get_title() const;
    std::string get_description() const;    
};

news::news(/*std::string author, */std::string title, std::string description) :
    /*author(author), */title(title), description(description) {}
news::news()
{
}

news::~news()
{
}

// void news::set_author(std::string author) {this->author = author; }
void news::set_title(std::string title) {this->title = title; }
void news::set_description(std::string description) {this->description = description; }
// void news::fill_news(std::string author, std::string title, std::string desc) {
//     set_author(author);
//     set_title(title);
//     set_description(desc);
// }

// std::string news::get_author() const { return author; }
std::string news::get_title() const { return title; }
std::string news::get_description() const { return description; }


News_Api_Handler::News_Api_Handler() { }
News_Api_Handler::~News_Api_Handler() { }

std::list<news> news_list;

void News_Api_Handler::get_data(std::string request) {
    
    
    json json_data;
    bool res = Api_Handler::send_request(query, api_key, params, request, &readBuffer);
    int i = 0;
    if (res) {
        json_data = json::parse(readBuffer);
        // std::cout << json_data << std::endl;
        if (json_data["status"] != "ok") {
            std::cout << "request is not OK" << std::endl;
            exit(EXIT_FAILURE);
        } else {
            for (auto article_info : json_data["articles"]){
                // std::cout << article_info["title"] << "\t\t\t" << article_info["title"] << std::endl << article_info["description"] << std::endl;
                // std::cout << "************************" << std::endl;
                ++i;
                news newss(/*article_info["author"].get<std::string>(), */article_info["title"],article_info["description"]);
                //news newss;
                //newss.fill_news(article_info["description"]);
                news_list.push_back(newss);
            }
            // std::cout << json_data["articles"] << std::endl;
            // std::cout << i << std::endl;
        }
    }
}

void News_Api_Handler::print_data() const {
    for (auto single_news : news_list)
    {
        std::cout << single_news.get_title()              << std::endl
                  << single_news.get_description()        << std::endl
                  << "**************************************" << std::endl << std::endl;
                  /*<< "\t\t\t" << single_news.get_author() << std::endl;*/
    }
}