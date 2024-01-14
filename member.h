#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "book.h"
#include "person.h"

class person;

class member : public person {
private:
    int memberID;
    std::vector<book> booksLoaned;

public:
    member() {}
    member(int memberID, std::string name, std::string address, std::string email);
    int getMemberID();
    std::vector<book> getBooksBorrowed();
    void setBooksBorrowed(book bookOBJ);
    void deleteBorrowedBook(int bookID);
};
#endif