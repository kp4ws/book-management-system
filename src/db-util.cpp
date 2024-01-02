#include "db-util.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

const std::string DbUtil::FILE_NAME = "resources/db.csv";

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

void DbUtil::saveBookToDatabase(const Book& book)
{
    std::ofstream file;
    file.open(FILE_NAME, std::ios::out | std::ios::app);
    file << book._isbn << "," << book._title << "," << book._description << std::endl;
    file.close();
}

void DbUtil::updateInDatabase(const Book &book)
{
    std::ifstream inFile(FILE_NAME);
    std::ofstream outFile("temp.csv");
    std::string line;

    if (!inFile.good() || !inFile.is_open())
    {
        std::string message = "Failed to open file: " + FILE_NAME;
        throw std::runtime_error(message);
    }

    while (std::getline(inFile, line))
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
        std::string title = "";
        std::string description = "";

        if(isbn == book._isbn)
        {
            outFile << tokens[0] << "," << book._title << "," << book._description << std::endl;
        }
        else
        {
            outFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << std::endl;
        }

        inFile.close();
        outFile.close();

        std::remove(FILE_NAME.c_str());
        std::rename("temp.csv", FILE_NAME.c_str());
    }
}

void DbUtil::deleteFromDatabase(int isbnToDelete)
{
    std::ifstream inFile(FILE_NAME);
    std::ofstream outFile("temp.csv");
    std::string line;

    if (!inFile.good() || !inFile.is_open())
    {
        std::string message = "Failed to open file: " + FILE_NAME;
        throw std::runtime_error(message);
    }

    while (std::getline(inFile, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() != 3 || std::stoi(tokens[0]) == isbnToDelete)
            continue;

        outFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << std::endl;
    }

    inFile.close();
    outFile.close();

    std::remove(FILE_NAME.c_str());
    std::rename("temp.csv", FILE_NAME.c_str());
}