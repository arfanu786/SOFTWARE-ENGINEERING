#include "book.h"
#include <iomanip>
#include <sstream>

book::book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName, std::string bookType) {
    this->bookID = bookID;
    this->bookName = bookName;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
    this->bookType = bookType;
}

void book::setDueDate(std::tm dueDate) {
    this->dueDate = dueDate;
}

void book::returnBook() {
    this->borrower = nullptr;  // reset borrower to a default member
    this->dueDate = std::tm();  // reset due date
}

void book::borrowBook(member* borrower, std::tm dueDate) {
    this->borrower = borrower;
    this->setDueDate(dueDate);
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

std::tm book::getDueDate() {
    return dueDate;
}