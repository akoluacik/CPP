#include <iostream>
#include "emergencyResponse.h"
#include <cstdlib>

responseTypedef response_array[3] = {PENDING, NEGATIVE, POSITIVE};
emergencyTypedef emergency_type_array[3] = {HEALTH, SECURITY, FIREFIGHTER};

responseTypedef responseHandler() {
    int idx = rand() % 3;
    std::cout << "idx: " << idx << std::endl;
    return response_array[idx];
}

void resultHandler(emergencyResponse emerg) {
    std::string respType_str = "Negative";
    std::string emergType_str = "Health";

    if(emerg.getResponse() == POSITIVE) {
        respType_str = "Positive";
    }

    if(emerg.getEmergencyType() == SECURITY) {
        emergType_str = "Security";
    } else if(emerg.getEmergencyType() == FIREFIGHTER) {
        emergType_str = "FireFighter";
    }

    std::cout << "Name: " << emerg.getFullName() << std::endl
              << "Phone Number: " << emerg.getphoneNumber() << std::endl
              << "Location: " << emerg.getLocation() << std::endl
              << "Emergency Type: " << emergType_str << std::endl
              << "Response: " << respType_str << std::endl
              << "Date: " << emerg.getDate() << std::endl << std::endl;
} 

int main(int argc, char const *argv[])
{
    std::string fullName, phoneNumber, location, temp;
    int emergencyType_idx;
    responseTypedef response;

    for (size_t i = 0; i < 5; i++)
    {

        std::cout << "Give your full name:";
        std::cin >> fullName >> temp;


        std::cout << "Give your phone number:";
        std::cin >> phoneNumber;

        std::cout << "Give your location:";
        std::cin >> location;

        std::cout << "Give your emergency type:" << std::endl << "1: HEALTH" << std::endl << "2: SECURITY" << std::endl << "3: FIREFIGHTER" << std::endl;
        std::cin >> emergencyType_idx;

        do
        {   
            response = responseHandler();
            std::cout << "Your request is waiting to be replied" << std::endl;;
        } while (response == PENDING);

        if(response == POSITIVE) {
            std::cout << "Your request has been Accepted!Officers will be directed" << std::endl;
        } else {
            std::cout << "Your request has been Rejected!" << std::endl;
        }
        
        emergencyResponse emerg = emergencyResponse(fullName, phoneNumber, location, emergency_type_array[emergencyType_idx], response);
        resultHandler(emerg);
    }

    return 0;
}
