#include <string>
#include <iostream>

#ifndef Book_h
#define Book_h

class Book
{
public:
    std::string Name;
    std::string Author;
    int Pages;
    int Year;

    ~Book();
    Book();
    Book(const std::string& Name, const std::string& Author, int Pages, int Year);
    // �������� ���� ��������
    void ChangeName(const std::string& name);
    void ChangeAuthor(const std::string& author);
    void ChangePages(int pages);
    void ChangeYear(int year);
    friend std::ostream& operator << (std::ostream& os, const Book& book);
    //����� ����
    std::string getname() const;
    std::string getauthor() const;
    int getpages() const;
    int getyear() const;
};

#endif
