#include <iostream>
#include "book-model.hpp"

class BookController
{
public:
    void createBook(int isbn, std::string title, std::string description)
    {
        BookModel book(isbn, title, description);
        //TODO persist book in the database
    }

    void readBook(int bookISBN)
    {
        
    }

    void updateBook(int currentBookISBN, int newBookISBN, std::string newTitle, std::string newDescription)
    {

    }

    void deleteBook(int bookISBN)
    {

    }
};