#include <iostream>
#include "book.hpp"

std::ostream &operator<<(std::ostream &os, const Book &book)
{
    os << "ISBN: " << book.getISBN() << std::endl;
    os << "Title: " << book.getTitle() << std::endl;
    os << "Description: " << book.getDescription() << std::endl;
    return os;
}

std::string Book::getCSVFormat() const {
    return _isbn + "," + _title + "," + _description;
}

std::string Book::getStandardFormat() const {
    return _isbn + "," + _title + "," + _description;
}