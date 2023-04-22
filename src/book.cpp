#include "book.hpp"
#include <iostream>
#include <sstream>

std::ostream &operator<<(std::ostream &os, const Book &book)
{
    os << book._isbn << "," << book._title << "," << book._description;
    return os;
}

std::string Book::getCSVFormat() const {
    return _isbn + "," + _title + "," + _description;
}

std::string Book::getStandardFormat() const {
    std::ostringstream oss;
    oss << "ISBN: " << _isbn << std::endl;
    oss << "Title: " << _title << std::endl;
    oss << "Description: " << _description << std::endl;
    return oss.str();
}