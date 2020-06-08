#include "Book.h"
Book::~Book() {
};
Book::Book() {
    Name = "";
    Author = "";
    Pages = Year = 0;
};

Book::Book(const std::string& Name, const std::string& Author, int Pages, int Year) {
    this->Name = Name;
    this->Author = Author;
    this->Pages = Pages; 
    this->Year = Year;
};

void Book::ChangeName(const std::string& name) {
    (*this).Name = name;
};

void Book::ChangeAuthor(const std::string& author) {
    (*this).Author = author;
};

void Book::ChangePages(int pages) {
    (*this).Pages = pages;
};

void Book::ChangeYear(int year) {
    (*this).Year = year;
};

std::ostream& operator << (std::ostream& os, const Book& book) {
    os << "Name - " << book.Name 
       << " Author - " << book.Author 
       << " Pages - " << book.Pages 
       << " Year - " << book.Year << std::endl;
    return os;
}
std::string Book::getname() const {
    return Name;
};

std::string Book::getauthor() const {
    return Author;
};

int Book::getpages() const {
    return Pages;
};

int Book::getyear() const {
    return Year;
};


