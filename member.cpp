#include "member.h"  //member class implementing
#include "person.h"

member::member(int memberID, std::string name, std::string address, std::string email) {
    this->memberID = memberID;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
}
//implementing getters
int member::getMemberID() {
    return this->memberID;
}

std::vector<book> member::getBooksBorrowed() {
    return this->booksLoaned;
}
//add borrowd books to members
void member::setBooksBorrowed(book bookOBJ) {
    this->booksLoaned.push_back(bookOBJ);
}

void member::deleteBorrowedBook(int bookID) {
    for (auto it = this->booksLoaned.begin(); it != this->booksLoaned.end(); ++it) {
        if (it->getBookID() == bookID) {
            this->booksLoaned.erase(it);
            break;
        }
    }
}