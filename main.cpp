#include <iostream>
#include <string>
#include <fstream>
#include "librarian.h"

bool fileExists(const std::string& fileName) {
    std::ifstream file(fileName);
    return file.good();
}

int main() {
    librarian librarianOBJ(1, 1000, "John Doe", "123 Fake Street", "john@gmail.com");
    std::string fileName;

    do {
        std::cout << "Enter file name (e.g., library_books.csv): ";
        getline(std::cin, fileName);
        std::cout << "Checking if file exists: " << fileName << std::endl;  // Debugging output
        if (fileExists(fileName) == false)
            std::cout << "File does not exist. Enter Again!" << std::endl;
    } while (fileExists(fileName) == false);

    librarianOBJ.inputBooks(fileName);
    system("cls");

    while (true) {
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
        system("pause");
        system("cls");
    }

    return 0;
}
