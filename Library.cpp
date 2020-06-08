#include "Library.h"

Library::~Library(){
};

Library::Library() {
    NameOfLibrary = "";
    Cases = 0;
    Places = 0;
    Books.empty();
};

Library::Library(const std::string& NameOfLibrary, int Cases, int Places) {
    this->NameOfLibrary = NameOfLibrary;
    this->Cases = Cases;
    this->Places = Places;
    this->Books.empty();
};

void Library::AddBookInLibrary(Book& book) {
    (*this).Books.push_back(book);
};

void Library::DeleteBookFromLibrary(const std::string name) {
    for (auto it = Books.begin(); it != Books.end(); ++it) {
        if (it->Name == name) {
            Books.erase(it);
            break;
        }
    }
};

void Library::DeleteAuthorFromLibrary(const std::string& author) {
        for (auto it = Books.begin(); it != Books.end(); ++it) {
            if (it->Author == author) {
                Books.erase(it);
                break;
            }
        }
};

std::ostream& operator << (std::ostream& os, const Library& library) {
    os << "NameOfLibrary - " << library.NameOfLibrary 
       << " Cases - " << library.Cases 
       << " Places - " << library.Places << std::endl;
    for (auto it = library.Books.begin(); it != library.Books.end(); it++) {
        os << *it;
    }
    return os;
};

std::string Library::getNameOfLibrary() {
    return NameOfLibrary;
};

int Library::getCases() {
    return Cases;
};

int Library::getPlaces() {
    return Places;
};

Library Library::operator +(Book& book) {
    (*this).Books.push_back(book);
    return *this;
}

void Library::findbyname(const std::string& name) {
    for (auto it = Books.begin(); it != Books.end(); ++it) {
        if (it->Name == name) {
            std::cout << *it;
        }
    }
};

void Library::findbyauthor(const std::string& author) {
    for (auto it = Books.begin(); it != Books.end(); ++it) {
        if (it->Author == author) {
            std::cout << *it;
        }
    }
};

void Library::findbypage(int page) {
    for (auto it = Books.begin(); it != Books.end(); ++it) {
        if (it->Pages == page) {
            std::cout << *it;
        }
    }
};

void Library::findbyyear(int year) {
    for (auto it = Books.begin(); it != Books.end(); ++it) {
        if (it->Year == year) {
            std::cout << *it;
        }
    }
};

void Library::print() {
    for (auto it = (*this).Books.begin(); it != (*this).Books.end(); it++) {
        std::cout << *it;
    }
};

std::ofstream& operator <<(std::ofstream& of, const Library& library) {
    of.open("Book.txt");
    for (auto it = library.Books.begin(); it != library.Books.end(); it++) {
        of << it->Name << " ";
        of << it->Author << " ";
        of << it->Pages << " ";
        of << it->Year << " " << std::endl;
    }
    of.close();
    return of;
};

std::ifstream& operator >>(std::ifstream& ifs, Library& library) {
    std::string name = "", author = "";
    int pages = 0;
    int year = 0;
    ifs.open("Book.txt");
    while (ifs) {
        ifs >> name;
        ifs >> author;
        ifs >> pages;
        ifs >> year;
        Book byfile(name, author, pages, year);
        library.AddBookInLibrary(byfile);
    }
    
    ifs.close();
    return ifs;
};

void Library::Sortauthor() {
    for (auto it1 = (*this).Books.begin(); it1 != (*this).Books.end(); it1++) {
        for (auto it2 = (*this).Books.begin(); it2 != (*this).Books.end(); it2++) {
            auto it3 = it2;
            if (it2->Author > (it3++)->Author) {
                std::swap(*it2, *it3);
            }
        }
    }
    
};

void Library::SortYear() {
    for (auto it1 = (*this).Books.begin(); it1 != (*this).Books.end(); it1++) {
        for (auto it2 = (*this).Books.begin(); it2 != (*this).Books.end(); it2++) {
            auto iter1 = it2;
            auto iter2 = it2;
            if (iter1->Year > (iter2++)->Year) {
                std::swap(*iter1, *iter2);
            }
        }
    }

};