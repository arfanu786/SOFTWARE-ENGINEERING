#ifndef BOOK_H
#define BOOK_H

#include <string>

class member; // Forward declaration

class book {
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    member* borrower;

public:
    book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName, std::string bookType);
    void returnBook();
    int getBookID();
    std::string getBookName();
    std::string getAuthorFirstName();
    std::string getAuthorLastName();
};

#endif
