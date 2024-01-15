#ifndef PERSON_H //person header file
#define PERSON_H

#include <string>

class person {
private:
    std::string name;
    std::string address;
    std::string email;

public:
    void setName(std::string name);//setters
    void setAddress(std::string address);
    void setEmail(std::string email);
    std::string getEmail();//getters
    std::string getName();
    std::string getAddress();
};
#endif