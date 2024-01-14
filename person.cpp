#include "person.h"

void person::setName(std::string name) {
    this->name = name;
}

void person::setAddress(std::string address) {
    this->address = address;
}

void person::setEmail(std::string email) {
    this->email = email;
}

std::string person::getName() {
    return this->name;
}

std::string person::getAddress() {
    return this->address;
}

std::string person::getEmail() {
    return this->email;
}