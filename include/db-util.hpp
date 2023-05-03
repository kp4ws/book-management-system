#ifndef __DB_UTIL_HEADER__
#define __DB_UTIL_HEADER__

#include "book.hpp"
#include <unordered_map>
#include <string>

class DbUtil
{
private:
    const std::string FILE_NAME = "resources/db.csv";

public:
    std::unordered_map<int, Book> retrieveFromDatabase();
    void saveToDatabase(const Book& book);
};

#endif