#pragma once
#include "Book.h"
#include <list>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <fstream>

#ifndef Library_h
#define Library_h

class Library 
{
public:
    std::string NameOfLibrary;
    std::list<Book> Books;
    int Cases; // количество шкафов для книг
    int Places; // количество мест для книг в одном шкафу

    ~Library();
    Library();
    Library(const std::string& NameofLibrary, int Cases, int Places);
    void AddBookInLibrary(Book& book); //добавить в список книгу
    void DeleteBookFromLibrary(const std::string name); //удалить книгу по названию
    void DeleteAuthorFromLibrary(const std::string& author); //удалить одну книгу данного автора
    friend std::ostream& operator <<(std::ostream& os, const Library& library);
    std::string getNameOfLibrary();
    int getCases();
    int getPlaces();

    Library operator +(Book& book);
    //поиск объекта по полю
    void findbyname(const std::string& name);
    void findbyauthor(const std::string& author);
    void findbypage(int page);
    void findbyyear(int year);

    void print(); //печать всех объектов списка
    // запись в файл и чтение из файла
    friend std::ofstream& operator <<(std::ofstream& of, const Library& library);
    friend std::ifstream& operator >>(std::ifstream& ifs, Library& library);
    //сортировка списка по выбранным полям(автор или год)
    void Sortauthor();
    void SortYear();
    
};


#endif