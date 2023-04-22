#include "db-util.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

std::unordered_map<int, Book> DbUtil::retrieveFromDatabase()
{
    std::unordered_map<int, Book> resultList;
    std::ifstream file(FILE_NAME);
    std::string line;

    if (!file.good() || !file.is_open())
    {
        std::string message = "Failed to open file: " + FILE_NAME;
        throw std::runtime_error(message);
    }

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() != 3)
        {
            std::cerr << "Invalid input line: " << line << std::endl;
            continue;
        }

        int isbn = std::stoi(tokens[0]);
        std::string title = tokens[1];
        std::string description = tokens[2];

        Book book(isbn, title, description);
        resultList.insert({isbn, book});
    }

    file.close();
    return resultList;
}

void DbUtil::saveToDatabase(const Book& book)
{
    std::ofstream file;
    file.open(FILE_NAME, std::ios::out | std::ios::app);
    file << book;
    file.close();
}