#ifndef __DB_UTIL_HEADER__
#define __DB_UTIL_HEADER__

#include <unordered_map>

class DbUtil
{
private:
    const std::string FILE_NAME = "db.csv";

public:
    std::unordered_map<int, Book> retrieveFromDatabase();
    void saveToDatabase(Book book);
};

#endif