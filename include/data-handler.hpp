#ifndef __DATA_HANDLER_HEADER__
#define __DATA_HANDLER_HEADER__

#include <unordered_map>
#include <string>
#include "book.hpp"
#include "db-util.hpp"
#include "ambiguous-isbn-exception.hpp"

class DataHandler
{
private:
    std::unordered_map<int, Book> _bookList;
    DbUtil _db;

public:
    DataHandler();
    void createBook(int isbn, std::string title, std::string description) throw(AmbiguousIsbnException);
    std::string displayBook(int isbn);
    void updateBook(int isbn, std::string newTitle, std::string newDescription);
    void deleteBook(int isbn);
};

#endif