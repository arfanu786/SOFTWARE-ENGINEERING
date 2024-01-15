#ifndef LIBRARIAN_H//librarian header file
#define LIBRARIAN_H

#include <string>
#include <vector>
#include "person.h"
#include "member.h"

class librarian : public person {
private:
    int staffID;
    int salary;
    std::vector<member> members;
    std::vector<book> books;
    
    //constructors
public:
    librarian(int staffID, std::string name, std::string address, std::string email);
    void addMember();//librarian responsabilities
    void issueBook(int memberID, int bookID);
    void returnBook(int memberID, int bookID);
    void displayBorrowedBooks(int memberID);
    int getStaffID();
    void setStaffID(int staffID);
    
    void inputBooks(std::string filename);
    void displayAllBooks();
};

#endif