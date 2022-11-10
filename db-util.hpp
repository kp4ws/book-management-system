#include <fstream>
#include <iostream>
#include <unordered_map>
//#include "book.hpp"
#include <iterator>

class DbUtil
{
    public:
        std::unordered_map<int, Book> retrieveFromDatabase()
        {
            std::unordered_map<int, Book> resultList;
            return resultList;
        }

        void saveToDatabase(std::unordered_map<int, Book> bookList)
        {
            std::ofstream file;
            file.open("db.csv");
            for (std::unordered_map<int, Book>::iterator it = bookList.begin(); it != bookList.end(); ++it)
            {
                int key = it->first;
                Book book = it->second;
                const std::string bookFormat = book.getISBN() + "," + book.getTitle() + "," + book.getDescription();
                file << bookFormat + "\n";
            }
            file.close();
        }
};