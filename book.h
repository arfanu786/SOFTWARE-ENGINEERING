#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <ctime>

class member; // forward declaration

class book {
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    std::tm dueDate;
    member* borrower;

public:
    book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName, std::string bookType);
    void setDueDate(std::tm dueDate);
    void returnBook();
    void borrowBook(member* borrower, std::tm dueDate);
    int getBookID();
    std::string getBookName();
    std::string getAuthorFirstName();
    std::string getAuthorLastName();
    std::tm getDueDate();

};

#endif