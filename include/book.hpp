#ifndef __BOOK_HEADER__
#define __BOOK_HEADER__

#include <string>
#include <iostream>

struct Book {
    int _isbn;
    std::string _title;
    std::string _description;

    Book(int isbn, std::string title, std::string description) : _isbn(isbn), _title(title), _description(description){}
    
    void display() const {
        std::cout << "ISBN: " << _isbn << "\nTitle: " << _title << "\nDescription: " << _description << std::endl;
    }
};

#endif