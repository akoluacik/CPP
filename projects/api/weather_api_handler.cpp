#include "weather_api_handler.h"
#include <nlohmann/json.hpp>
#include <list>
#include <iostream>
#include <iomanip>

class weather
{
private:
    double      feels_like;
    double      temp;
    double      temp_min;
    double      temp_max;
    double      pressure;
    double      humidity;
    std::string description;
    double      wind_speed;
    double      wind_degree;

public:
    weather();
    void set_feels_like(double feels_like);
    void set_temp(double temp);
    void set_temp_max(double temp_max);
    void set_temp_min(double temp_min);
    void set_pressure(double pressure);
    void set_humidity(double humidity);
    void set_description(std::string description);
    void set_wind_speed(double wind_speed);
    void set_wind_degree(double wind_degree);


    double get_feels_like() const;
    double get_temp() const;
    double get_temp_min() const ;
    double get_temp_max() const ;
    double get_humidity() const ;
    double get_pressure() const ;
    double get_wind_speed() const; 
    double get_wind_degree() const;

    std::string get_description() const;

    ~weather();
};

weather::weather() { }

void weather::set_feels_like(double feels_like) { this->feels_like = feels_like; }
void weather::set_temp(double temp) { this->temp = temp; }
void weather::set_temp_max(double temp_max) { this->temp_max = temp_max; }
void weather::set_temp_min(double temp_min) { this->temp_min = temp_min; }
void weather::set_pressure(double pressure) { this->pressure = pressure; }
void weather::set_humidity(double humidity) { this->humidity = humidity; }
void weather::set_description(std::string description) { this->description = description; }
void weather::set_wind_speed(double wind_speed) { this->wind_speed = wind_speed; }
void weather::set_wind_degree(double wind_degree) { this->wind_degree; }

double weather::get_feels_like() const { return feels_like; }
double weather::get_temp() const { return temp; }
double weather::get_temp_min() const { return temp_min; }
double weather::get_temp_max() const { return temp_max; }
double weather::get_humidity() const { return humidity; }
double weather::get_pressure() const { return pressure; }
double weather::get_wind_speed() const { return wind_speed; }
double weather::get_wind_degree() const { return wind_degree; }
std::string weather::get_description() const { return description; }

weather::~weather()
{
}

using json = nlohmann::json;

Weather_Api_Handler::Weather_Api_Handler() {}
Weather_Api_Handler::~Weather_Api_Handler() {}

weather weatherr;

void Weather_Api_Handler::get_data(std::string request) {
    
    json parsed_data;
    
    bool res = Api_Handler::send_request(query, api_key, params, request, &readBuffer);
    
    if (res) {
        parsed_data = json::parse(readBuffer);
        // std::cout << "parsed_data:" << parsed_data << std::endl;
        // assert(parsed_data["cod"].get<std::int32_t>() != 200);
        std::cout << "cod:" << parsed_data["cod"] << std::endl;
        if (parsed_data["cod"].get<std::int32_t>() != 200) {
            std::cout << "cod != 200" << std::endl;
            exit(EXIT_FAILURE);
        }
        else {
            // std::cout << "cod:200" << std::endl;
            // std::cout << "description:";
            // std::cout << parsed_data["weather"][0]["description"] << std::endl;
            std::cout << "else" << std::endl;
            weatherr.set_description(parsed_data["weather"][0]["description"].get<std::string>());
            weatherr.set_feels_like(parsed_data["main"]["feels_like"].get<double>());
            weatherr.set_temp_min(parsed_data["main"]["temp"].get<double>());
            weatherr.set_temp_min(parsed_data["main"]["temp_min"].get<double>());
            weatherr.set_temp_max(parsed_data["main"]["temp_max"].get<double>());
            weatherr.set_humidity(parsed_data["main"]["humidity"].get<double>());
            weatherr.set_pressure(parsed_data["main"]["pressure"].get<double>());
            weatherr.set_wind_speed(parsed_data["wind"]["speed"].get<double>());
            weatherr.set_wind_degree(parsed_data["wind"]["deg"].get<double>());

            // set precision ayarla
            // result  = "hava_durumu: " + parsed_data["weather"][0]["description"].get<std::string>() + "\n"
            //         + "sıcaklık: " + std::to_string(parsed_data["main"]["temp"].get<double>())  + "\n"
            //         + "hissedilen: " + std::to_string(parsed_data["main"]["feels_like"].get<double>())  + "\n"
            //         + "en düşük: " + std::to_string(parsed_data["main"]["temp_min"].get<double>())    + "\n"
            //         + "en yüksek: " + std::to_string(parsed_data["main"]["temp_max"].get<double>())    + "\n"
            //         + "basınç: " + std::to_string(parsed_data["main"]["pressure"].get<double>())    + "\n"
            //         + "nem: "+ std::to_string(parsed_data["main"]["humidity"].get<double>())    + "\n"
            //         ;
            // std::cout << parsed_data;
        }
    }
}

void Weather_Api_Handler::print_data() const {
    
    // std::cout << std::setw(14) << std::left << "Hava Durumu:" << weatherr.get_description() << std::endl
    //           << std::setw(14) << std::left << "Hissedilen:"   /*<< std::setprecision(2)*/ << weatherr.get_feels_like() << std::endl
    //           << std::setw(14) << std::left << "En Yüksek:"    /*<< std::setprecision(2)*/ << weatherr.get_temp_max() << std::endl
    //           << std::setw(14) << std::left << "En Düşük:"     /*<< std::setprecision(2)*/ << weatherr.get_temp_min() << std::endl
    //           << std::setw(14) << std::left << "Basınç:"       /*<< std::setprecision(2)*/ << weatherr.get_pressure() << std::endl
    //           << std::setw(14) << std::left << "Nem:"          /*<< std::setprecision(2)*/ << weatherr.get_humidity() << std::endl;

    std::cout << std::setw(14) << std::left << "Hava Durumu:" << std::setw(15) << std::right << weatherr.get_description() << std::endl
              << std::setw(14) << std::left << "Sıcaklık:"   << std::setw(13) << std::right << weatherr.get_temp() << std::endl
              << std::setw(14) << std::left << "Hissedilen:"  << std::setw(12) << std::right << weatherr.get_feels_like() << std::endl
              << std::setw(14) << std::left << "En Yüksek:"   << std::setw(13) << std::right << weatherr.get_temp_max() << std::endl
              << std::setw(14) << std::left << "En Düşük:"    << std::setw(15) << std::right << weatherr.get_temp_min() << std::endl
              << std::setw(14) << std::left << "Basınç:"      << std::setw(12) << std::right << weatherr.get_pressure() << std::endl
              << std::setw(14) << std::left << "Nem:"         << std::setw(8) << std::right << weatherr.get_humidity() << std::endl
              << std::setw(14) << std::left << "Rüzgar Hızı:"         << std::setw(8) << std::right << weatherr.get_wind_speed() << std::endl
              << std::setw(14) << std::left << "Rüzgar Derecesi:"     << std::setw(8) << std::right << weatherr.get_wind_degree() << std::endl;
}
