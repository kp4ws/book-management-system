#ifndef __INPUT_HANDLER_HEADER__
#define __INPUT_HANDLER_HEADER__

#include "data-handler.hpp"

class InputHandler
{
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

    void handleCreate();
    void handleDisplay();
    void handleUpdate();
    void handleDelete();

public:
    InputHandler(){}
    void readInput();
};

#endif