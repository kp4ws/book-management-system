#include <iostream>
#include <string>
#include "data-handler.hpp"

class InputHandler
{
public:
    InputHandler() {}
    ~InputHandler() {}

    void readInput()
    {
        int userInput = 0;
        std::string unparsedInput = "";
        while (userInput != EXIT)
        {
            std::cout << "\n1. Add Book\n2. Display Book\n3. Edit Book\n4. Delete Book\n-1 Save and Exit\n\n Enter option: ";
            std::cin >> unparsedInput;

            userInput = stoi(unparsedInput);

            switch (userInput)
            {
            case CREATE:
                handleCreate();
                break;
            case READ:
                handleDisplay();
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

private:
    DataHandler dataHandler;

    enum Program_Type
    {
        EXIT = -1,
        CREATE = 1,
        READ = 2,
        UPDATE = 3,
        DELETE = 4
    };

    void handleCreate()
    {
        std::string unparsedIsbn = "", title = "", description = "";

        std::cout << "Enter isbn: ";
        std::cin >> unparsedIsbn;
        std::cout << "Enter title: ";
        std::cin >> title;
        std::cout << "Enter description: ";
        std::cin >> description;

        dataHandler.createBook(stoi(unparsedIsbn), title, description);
    }

    void handleDisplay()
    {
        std::string unparsedIsbn = "";
        std::cout << "Enter isbn: ";
        std::cin >> unparsedIsbn;

        dataHandler.displayBook(stoi(unparsedIsbn));
    }

    //You cannot update isbn
    void handleUpdate()
    {
        std::string unparsedIsbn = "", newTitle = "", newDescription = "";
        std::cout << "Enter isbn of book you want to update: ";
        std::cin >> unparsedIsbn;
        std::cout << "Enter title: ";
        std::cin >> newTitle;
        std::cout << "Enter description: ";
        std::cin >> newDescription;

        dataHandler.updateBook(stoi(unparsedIsbn), newTitle, newDescription);
    }

    void handleDelete()
    {
        std::string unparsedIsbn = "";
        std::cout << "Enter isbn: ";
        std::cin >> unparsedIsbn;

        std::cout << "Are you sure you want to delete: " << unparsedIsbn << "? (1 = yes, 0 = no)" << std::endl;
        std::string exitCondition = "";
        std::cin >> exitCondition;
        if(stoi(exitCondition) == 0)
            return;

        dataHandler.deleteBook(stoi(unparsedIsbn));
    }
};