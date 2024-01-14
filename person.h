#ifndef PERSON_H
#define PERSON_H

#include <string>

class person {
private:
    std::string name;
    std::string address;
    std::string email;

public:
    void setName(std::string name);
    void setAddress(std::string address);
    void setEmail(std::string email);
    std::string getEmail();
    std::string getName();
    std::string getAddress();
};
#endif