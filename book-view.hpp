#include <iostream>
#include <string>
#include "book-controller.hpp"

class BookView
{
public:
    BookView() { handleInput(); }
    ~BookView() {}

private:
    enum Program_Type
    {
        EXIT = -1,
        CREATE = 1,
        READ = 2,
        UPDATE = 3,
        DELETE = 4
    };

    BookController controller;

    void handleCreate()
    {
        std::string unparsedIsbn = "", title = "", description = "";

        std::cout << "Enter isbn: ";
        std::cin >> unparsedIsbn;
        std::cout << "Enter title: ";
        std::cin >> title;
        std::cout << "Enter description: "; // TODO: later iteration could set max limit of characters
        std::cin >> description;

        controller.createBook(stoi(unparsedIsbn), title, description);
    }

    void handleRead()
    {
        std::string unparsedIsbn = "";
        std::cout << "Enter isbn: ";
        std::cin >> unparsedIsbn;

        controller.readBook(stoi(unparsedIsbn));
    }

    void handleUpdate()
    {
        std::string unparsedIsbn = "";
        std::cout << "Enter isbn of book you want to update: ";
        std::cin >> unparsedIsbn;

        // TODO: enter new data for book
        // isbn, title, description

        controller.updateBook(0, 0, "", "");
    }

    void handleDelete()
    {
        // TODO: Confirm message that user wants to delete book
        // are you sure you want to delete? (-1 to go back)

        std::string unparsedIsbn = "";
        std::cout << "Enter isbn: ";
        std::cin >> unparsedIsbn;

        controller.deleteBook(stoi(unparsedIsbn));
    }

    void handleInput()
    {
        int userInput = 0;
        std::string unparsedInput = "";
        while (userInput != EXIT)
        {
            std::cout << "1. Add Book\n2. Display Book\n3. Edit Book\n4. Delete Book\n-1 Save and Exit\n\n Enter option: ";
            std::cin >> unparsedInput;

            userInput = stoi(unparsedInput);

            switch (userInput)
            {
            case CREATE:
                handleCreate();
                break;
            case READ:
                handleRead();
                break;
            case UPDATE:
                handleUpdate();
                break;
            case DELETE:
                handleDelete();
                break;

            case EXIT:
                break;

            default:
                std::cout << "***Invalid input***\n"
                          << std::endl;
                break;
            }
        }
    }
};