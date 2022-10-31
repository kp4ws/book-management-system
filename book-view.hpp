#include <iostream>
#include <vector>
#include <string>

class BookView
{
public:
    BookView() {handleInput();}
    ~BookView() {}

private:
    enum Program_Type
    {
        EXIT = -1,
        CREATE,
        READ,
        UPDATE,
        DELETE
    };

    void handleInput()
    {
        int userInput = 0;
        std::string unparsedInput = "";
        while (userInput != EXIT)
        {
            std::cout << "1. Add Book\n2. Display Book\n3. Edit Book\n4. Delete Book\n-1 Save and Exit\n\n Enter option: " << std::endl;
            std::cin >> unparsedInput;

            userInput = stoi(unparsedInput);

            switch (userInput)
            {
            case CREATE:
                // TODO: call controller method
                std::cout << "***Book created***\n"
                          << std::endl;
                break;
            case READ:
                // TODO: call controller method
                std::cout << "***Book displayed***\n"
                          << std::endl;
                break;
            case UPDATE:
                // TODO: call controller method
                std::cout << "***Book updated***\n"
                          << std::endl;
                break;
            case DELETE:
                // TODO: call controller method
                std::cout << "***Book deleted***\n"
                          << std::endl;
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