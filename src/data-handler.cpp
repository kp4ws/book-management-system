#include "data-handler.hpp"
#include <iostream>
#include <unordered_map>

DataHandler::DataHandler() : _bookList(_db.retrieveFromDatabase()) {}

void DataHandler::createBook(int isbn, std::string title, std::string description)
{
    if (_bookList.count(isbn) > 0)
        throw AmbiguousIsbnException();

    Book book(isbn, title, description);
    _bookList.insert({book._isbn, book});
    _db.saveBookToDatabase(book);
}

void DataHandler::displayBook(int isbn)
{
    if (_bookList.count(isbn) == 0)
    {
        std::cout << "No books matching ISBN: " << isbn << '\n';
        return;
    }

    Book book = _bookList.at(isbn);
    book.display();
}

void DataHandler::updateBook(int isbn, std::string newTitle, std::string newDescription)
{
    if (_bookList.count(isbn) == 0)
    {
        std::cout << "No books matching ISBN: " << isbn << '\n';
        return;
    }

    Book book = _bookList.at(isbn);
    book._title = newTitle;
    book._description = newDescription;

    _db.updateInDatabase(book);
}

void DataHandler::deleteBook(int isbn)
{
    if (_bookList.count(isbn) == 0)
    {
        std::cout << "No books matching ISBN: " << isbn << '\n';
        return;
    }
    _bookList.erase(isbn);
    _db.deleteFromDatabase(isbn);
}