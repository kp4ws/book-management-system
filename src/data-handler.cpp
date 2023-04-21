#include "data-handler.hpp"
#include <iostream>
#include <unordered_map>

DataHandler::DataHandler() : _bookList(_db.retrieveFromDatabase()) {}

void DataHandler::createBook(int isbn, std::string title, std::string description) throw(AmbiguousIsbnException)
{
    if (_bookList.count(isbn) > 0)
        throw AmbiguousIsbnException();

    Book book(isbn, title, description);
    _bookList.insert({book.getISBN(), book});
    _db.saveToDatabase(book);
}

std::string DataHandler::displayBook(int isbn)
{
    if (_bookList.count(isbn) == 0)
    {
        std::cout << "No books matching ISBN: " << isbn << '\n';
        return "";
    }

    Book book = _bookList.at(isbn);
    return book.getStandardFormat();
}

void DataHandler::updateBook(int isbn, std::string newTitle, std::string newDescription)
{
    if (_bookList.count(isbn) == 0)
    {
        std::cout << "No books matching ISBN: " << isbn << '\n';
        return;
    }

    Book book = _bookList.at(isbn);
    Book newBook(book.getISBN(), newTitle, newDescription);
    book = newBook;
}

void DataHandler::deleteBook(int isbn)
{
    if (_bookList.count(isbn) == 0)
    {
        std::cout << "No books matching ISBN: " << isbn << '\n';
        return;
    }
    _bookList.erase(isbn);
}