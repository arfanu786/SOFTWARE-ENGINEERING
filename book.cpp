#include "book.h"

book::book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName, std::string bookType) {
    this->bookID = bookID;
    this->bookName = bookName;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
    this->bookType = bookType;
    this->borrower = nullptr;  // Initialize borrower to nullptr
}

void book::returnBook() {
    this->borrower = nullptr;  // Reset borrower to nullptr
}

int book::getBookID() {
    return this->bookID;
}

std::string book::getBookName() {
    return this->bookName;
}

std::string book::getAuthorFirstName() {
    return this->authorFirstName;
}

std::string book::getAuthorLastName() {
    return this->authorLastName;
}

