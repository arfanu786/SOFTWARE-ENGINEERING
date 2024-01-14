#include <iostream>
#include <string>
#include <fstream>
#include "librarian.h"


bool fileExists(const std::string& fileName) {
    std::ifstream file(fileName);
    return file.good();
}

int main() {
    librarian librarianOBJ(1, 1000, "Arfanul Shouid", "71 Maple Street", "arfanul@gmail.com");
    std::string fileName;

    bool checkFile;
    do {
        std::cout << "Enter file name (e.g, file.csv): ";
        getline(std::cin, fileName);
        checkFile = fileExists(fileName);
        if (checkFile == false) {
            std::cout << "File does not exist. Enter Again!" << std::endl;
            
        }
    } while(checkFile == false);
    librarianOBJ.inputBooks(fileName);
    

    while(true) {
        char choice;
        std::cout << "MENU" << std::endl;
        std::cout << "----" << std::endl;
        std::cout << "1. Add member" << std::endl;
        std::cout << "2. Issue book" << std::endl;
        std::cout << "3. Return book" << std::endl;
        std::cout << "4. Display borrowed books" << std::endl;
        std::cout << "5. Display all books" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch(choice) {
            case '1':
                librarianOBJ.addMember();
                break;
            case '2':
                int memberID, bookID;
                std::cout << "Enter member ID: ";
                std::cin >> memberID;
                std::cout << "Enter book ID: ";
                std::cin >> bookID;
                librarianOBJ.issueBook(memberID, bookID);
                break;
            case '3':
                std::cout << "Enter member ID: ";
                std::cin >> memberID;
                std::cout << "Enter book ID: ";
                std::cin >> bookID;
                librarianOBJ.returnBook(memberID, bookID);
                break;
            case '4':
                std::cout << "Enter member ID: ";
                std::cin >> memberID;
                librarianOBJ.displayBorrowedBooks(memberID);
                break;
            case '5':
                librarianOBJ.displayAllBooks();
                break;
            case '6':
                return 0;
            default:
                std::cout << "Invalid choice." << std::endl;
        }
       
    }

    return 0;
}