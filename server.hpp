#include "input-handler.hpp"

class Server
{
public:
    void startProgram()
    {
        std::cout << "\n===============\nBook Management System\n===============" << std::endl;
        try
        {
            InputHandler inputHandler;
            inputHandler.readInput();
            
            std::cout << "Program finished successfully" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "***PROGRAM ERROR***" << '\n';
        }
    }
};