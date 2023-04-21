#include <fstream>
#include <iostream>
#include <vector>
#include "db-util.hpp"

std::unordered_map<int, Book> DbUtil::retrieveFromDatabase()
{
    std::unordered_map<int, Book> resultList;
    std::string fileText;
    std::ifstream file;

    std::vector<std::string> dataList;
    file.open(FILE_NAME, std::ios::in);
    while (std::getline(file, fileText, ','))
    {
        dataList.push_back(fileText);
    }
    file.close();

    // TODO
    //  for (size_t i = 0; i < dataList.size(); i+=3)
    //  {
    //      //std::cout << dataList[] << std::endl;
    //      // int isbn = stoi(dataList[0 + i]);
    //      // std::string title = dataList[1 + i];
    //      // std::string description = dataList[2 + i];

    //     // Book book(isbn, title, description);
    //     // resultList.insert({isbn, book});
    // }

    return resultList;
}

void DbUtil::saveToDatabase(Book book)
{
    std::ofstream file;
    const std::string bookFormat = std::to_string(book.getISBN()) + "," + book.getTitle() + "," + book.getDescription();
    file.open(FILE_NAME, std::ios::out | std::ios::app);
    file << bookFormat + "\n";
    file.close();

    // THIS CODE IS USED TO REPLACE ENTIRE FILE
    //  for (std::unordered_map<int, Book>::iterator it = bookList.begin(); it != bookList.end(); ++it)
    //  {
    //      int key = it->first;
    //      Book book = it->second;
    //      const std::string bookFormat = std::to_string(book.getISBN()) + "," + book.getTitle() + "," + book.getDescription();
    //      file << bookFormat + "\n";
    //  }
}