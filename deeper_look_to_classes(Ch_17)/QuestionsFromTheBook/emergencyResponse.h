#ifndef __EMERGENCY_RESPONSE_H
#define __EMERGENCY_RESPONSE_H

#include <string>
#include <ctime>

typedef enum {
    HEALTH,
    SECURITY,
    FIREFIGHTER
} emergencyTypedef;

typedef enum {
    PENDING = -1,
    NEGATIVE,
    POSITIVE,
} responseTypedef;

class emergencyResponse
{
private:
    
    std::string fullName;
    std::string phoneNumber;
    std::string location;
    emergencyTypedef emergencyType;
    char* date;
    responseTypedef response;
    


public:
    emergencyResponse(std::string, std::string, std::string, emergencyTypedef, responseTypedef response);
    /*~emergencyResponse();*/
    
    void setFullName(std::string fullName);
    void setPhoneNumber(std::string phoneNumber);
    void setLocation(std::string location);
    void setEmergencyType(emergencyTypedef emergencyType);
    void setDate();
    void setResponse(responseTypedef response);

    std::string getFullName() const;
    std::string getphoneNumber() const;
    std::string getLocation() const;
    emergencyTypedef getEmergencyType() const;
    char* getDate() const;
    responseTypedef getResponse() const;
};

#endif // __EMERGENCY_RESPONSE_H
