#include <iostream>
#include <unordered_map>
#include "book.hpp"
#include "db-util.hpp"
#include "ambiguous-isbn-exception.hpp"

class DataHandler
{
public:
    DataHandler(){bookList = db.retrieveFromDatabase();}
    ~DataHandler() {}

    void createBook(int isbn, std::string title, std::string description)
    {
        if(bookList.count(isbn) > 0)
            throw AmbiguousIsbnException();

        Book book(isbn, title, description);
        bookList.insert({book.getISBN(), book});
        
        db.saveToDatabase(bookList);
    }

    void displayBook(int isbn)
    {
        if (bookList.count(isbn) == 0)
        {
            std::cout << "No books matching ISBN: " << isbn << '\n';
            return;
        }

        Book book = bookList.at(isbn);
        book.display();
    }

    void updateBook(int isbn, std::string newTitle, std::string newDescription)
    {
        if (bookList.count(isbn) == 0)
        {
            std::cout << "No books matching ISBN: " << isbn << '\n';
            return;
        }

        Book book = bookList.at(isbn);
        book.setTitle(newTitle);
        book.setDescription(newDescription);
    }

    void deleteBook(int isbn)
    {
        if (bookList.count(isbn) == 0)
        {
            std::cout << "No books matching ISBN: " << isbn << '\n';
            return;
        }
        bookList.erase(isbn);
    }

private:
    std::unordered_map<int, Book> bookList;
    DbUtil db;
};