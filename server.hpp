#include "book-view.hpp"

class Server
{
public:
    void startProgram()
    {
        initializeDatabase();
        std::cout << "\n===============\nBook Management System\n===============" << std::endl;
        try
        {
            BookView();
            std::cout << "Program finished successfully" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "***PROGRAM ERROR***" << '\n';
        }
    }

private:
    void initializeDatabase()
    {
        //csv file format
        //uid, isbn, bookName, bookDescription

    }
};