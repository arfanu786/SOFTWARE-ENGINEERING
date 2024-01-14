#include "librarian.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include "book.h"
#include "member.h"
#include <time.h>
#include <iomanip>

librarian::librarian(int staffID, int salary, std::string name, std::string address, std::string email) {
    this->staffID = staffID;
    this->salary = salary;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
}

void librarian::displayAllBooks(){
    
    std::cout << "All books in the library:" << std::endl;
    for (int i = 0; i < books.size(); i++) {
        std::cout << "Book " << i + 1 << " details:" << std::endl;
        std::cout << "Book Name: " << books[i].getBookName() << std::endl;
        std::cout << "Book ID: " << books[i].getBookID() << std::endl;
        std::cout << "Author: " << books[i].getAuthorFirstName() + " " + books[i].getAuthorLastName() << std::endl;
        // Display other book details as needed
        std::cout << "---------------------------" << std::endl;
    }
}

int librarian::getStaffID() {
    return this->staffID;
}

void librarian::setStaffID(int staffID) {
    this->staffID = staffID;
}

int librarian::getSalary() {
    return this->salary;
}

void librarian::setSalary(int salary) {
    this->salary = salary;
}

void librarian::displayBorrowedBooks(int memberID) {
    
    for (int i = 0; i < members.size(); i++) {
        if (members[i].getMemberID() == memberID) {
            std::vector<book> booksBorrowed = members[i].getBooksBorrowed();
            std::cout << "Books borrowed by " << members[i].getName() << ":" << std::endl;
            for (int j = 0; j < booksBorrowed.size(); j++) {
                std::cout << "Book " << j + 1 << " details:" << std::endl;
                std::cout << "Book Name: " << booksBorrowed[j].getBookName() << std::endl;
                std::cout << "Book ID: " << booksBorrowed[j].getBookID() << std::endl;
                std::cout << "Author: " << booksBorrowed[j].getAuthorFirstName() + " " + booksBorrowed[j].getAuthorLastName() << std::endl;
                // Display other book details as needed
                std::cout << "---------------------------" << std::endl;
            }
            return;
        }
    }
    std::cout << "Member not found.\n" << std::endl;
}

void librarian::addMember() {
    int id;
    std::cout << "Enter member ID: ";
    std::cin >> id;
    std::cin.ignore(); // Ignore the newline character left in the input stream

    std::string name, email, address;
    std::cout << "Enter member name: ";
    getline(std::cin, name);
    std::cout << "Enter member email: ";
    getline(std::cin, email);
    std::cout << "Enter member address: ";
    getline(std::cin, address);
    member newMember(id, name, address, email);
    members.push_back(newMember);
}

void librarian::issueBook(int memberID, int bookID) {
    for (int i = 0; i < members.size(); i++) {
        if (members[i].getMemberID() == memberID) {
            for (int j = 0; j < books.size(); j++) {
                if (books[j].getBookID() == bookID) {
                    members[i].setBooksBorrowed(books[j]);

                    // Set the due date to 3 days from now
                    std::time_t t = std::time(0);   // get time now
                    std::tm* now = std::localtime(&t);
                    now->tm_mday += 3;  // add 3 days
                    books[j].borrowBook(&members[i], *now);
                    std::cout << "Book issued." << std::endl;
                    return;
                }
            }
            std::cout << "Book not found." << std::endl;
            return;
        }
    }
    std::cout << "Member not found." << std::endl;
}

void librarian::returnBook(int memberID, int bookID) {
    for (int i = 0; i < members.size(); i++) {
        if (members[i].getMemberID() == memberID) {
            std::vector<book> books = members[i].getBooksBorrowed();
            for (int j = 0; j < books.size(); j++) {
                if (books[j].getBookID() == bookID) {
                    // Remove the book from the borrowed books list
                    books[j].returnBook();
                    members[i].deleteBorrowedBook(bookID);
                    std::cout << "Book returned." << std::endl;
                    return;
                }
            }
            std::cout << "Book not found." << std::endl;
            return;
        }
    }
    std::cout << "Member not found." << std::endl;
}

void librarian::inputBooks(std::string filename) {
    std::ifstream file(filename);

    // Skip the header line
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string field;
        std::vector<std::string> rowData;

        while (std::getline(ss, field, ',')) {
            rowData.push_back(field);
        }

        int bookID = std::stoi(rowData[0]);
        std::string bookName = rowData[1];
        std::string authorFirstName = rowData[3];
        std::string authorLastName = rowData[4];
        std::string bookType = rowData[5];

        books.push_back(book(bookID, bookName, authorFirstName, authorLastName, bookType));
    }
}
