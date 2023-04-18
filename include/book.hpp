#ifndef __BOOK_CONTAINER_HEADER__
#define __BOOK_CONTAINER_HEADER__

class Book
{

private:
    int _isbn;
    std::string _title;
    std::string _description;

public:
    Book(int newISBN, std::string newTitle, std::string newDescription) : _isbn(newISBN), _title(newTitle), _description(newDescription) {}
    int getISBN() const { return _isbn; }
    std::string getTitle() const { return _title; }
    std::string getDescription() const { return _description; }
};

#endif