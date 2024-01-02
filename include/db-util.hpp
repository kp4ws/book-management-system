#ifndef __DB_UTIL_HEADER__
#define __DB_UTIL_HEADER__

#include "book.hpp"
#include <unordered_map>
#include <string>

class DbUtil
{
private:
    const static std::string FILE_NAME;

public:
    std::unordered_map<int, Book> retrieveFromDatabase();
    void saveBookToDatabase(const Book &book);
    void updateInDatabase(const Book &book);
    void deleteFromDatabase(int isbnToDelete);
};

#endif