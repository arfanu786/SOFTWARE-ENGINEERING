#include <iostream>
#include <string>
#include <fstream>
#include "librarian.h"

// Function to check if a file exists
bool fileExists(const std::string& fileName) {
    std::ifstream file(fileName);
    return file.good();
}

int main() {
    // Creating an instance of the librarian class with initial information
  librarian librarianOBJ(1, "Arfanul Shouid", "71 Maple Street", "arfanul@gmail.com");

    std::string fileName;

    bool checkFile;

    // Using a do-while loop to prompt the user for a valid file name
    do {
        std::cout << "Enter file name (e.g., file.csv): ";
        getline(std::cin, fileName);
        checkFile = fileExists(fileName);
        if (checkFile == false) {
            std::cout << "File does not exist. Enter Again!" << std::endl;
        }
    } while (checkFile == false);

    // Calling the inputBooks function to populate the library with books from the file
    librarianOBJ.inputBooks(fileName);

    // Presenting a menu in a while loop for various librarian actions
    while (true) {
        char choice;

        // Displaying the menu options
        std::cout << "MENU" << std::endl;
        std::cout << "----" << std::endl;
        std::cout << "1. Add member" << std::endl;
        std::cout << "2. Issue book" << std::endl;
        std::cout << "3. Return book" << std::endl;
        std::cout << "4. Display borrowed books" << std::endl;
        std::cout << "5. Display all books" << std::endl;
        std::cout << "6. Exit" << std::endl;

        // Accepting user input for the selected menu option
        std::cout << "Enter choice: ";
        std::cin >> choice;

        // Switch statement to perform actions based on user choice
        switch (choice) {
            case '1':
                librarianOBJ.addMember(); // Invoking the addMember function
                break;
            case '2':
                int memberID, bookID;
                std::cout << "Enter member ID: ";
                std::cin >> memberID;
                std::cout << "Enter book ID: ";
                std::cin >> bookID;
                librarianOBJ.issueBook(memberID, bookID); // Invoking the issueBook function
                break;
            case '3':
                std::cout << "Enter member ID: ";
                std::cin >> memberID;
                std::cout << "Enter book ID: ";
                std::cin >> bookID;
                librarianOBJ.returnBook(memberID, bookID); // Invoking the returnBook function
                break;
            case '4':
                std::cout << "Enter member ID: ";
                std::cin >> memberID;
                librarianOBJ.displayBorrowedBooks(memberID); // Invoking the displayBorrowedBooks function
                break;
            case '5':
                librarianOBJ.displayAllBooks(); // Invoking the displayAllBooks function
                break;
            case '6':
                return 0; // Exiting the program
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    }

    return 0;
}
