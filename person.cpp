#include "person.h"//person class implementation

void person::setName(std::string name) {
    this->name = name;//setter implementing
}

void person::setAddress(std::string address) {
    this->address = address;
}

void person::setEmail(std::string email) {
    this->email = email;
}
//getter implementing
std::string person::getName() {
    return this->name;
}

std::string person::getAddress() {
    return this->address;
}

std::string person::getEmail() {
    return this->email;
}