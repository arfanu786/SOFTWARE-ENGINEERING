#ifndef MEMBER_H //member header file
#define MEMBER_H

#include <string>
#include <vector>
#include "book.h"
#include "person.h"

class person;

class member : public person {
private:
    int memberID;
    std::vector<book> booksLoaned; //books stored

public:
    member() {}
    member(int memberID, std::string name, std::string address, std::string email);
    int getMemberID();
    std::vector<book> getBooksBorrowed();//getters
    void setBooksBorrowed(book bookOBJ);//modifying methods
    void deleteBorrowedBook(int bookID);
};
#endif