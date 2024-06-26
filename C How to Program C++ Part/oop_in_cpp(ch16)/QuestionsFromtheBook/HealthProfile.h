#include <string>

class HealthProfile
{
public:
    HealthProfile (std::string firstName, std::string lastName,
                std::string gender, int month, int day, int year, double height, double weight);
    void setFirstName(std::string fName);
    void setLastName(std::string lName);
    void setGender(std::string _gender);
    void setBirthday (int _month, int _day, int _year);
    void setHeight(double _height);
    void setWeight(double _weight);
    

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getGender() const;
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    double getHeight() const;
    double getWeight() const;
    double BMI() const;
    int getMaximumHeartRate() const;
    double getTargetHeartRate() const; 
    void displayInfo() const;
    
private:
    std::string firstName, lastName;
    std::string gender;
    int month, day, year, age;
    double height, weight;
    void setAge(int year = 2021);
};