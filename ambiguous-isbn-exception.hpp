#include <iostream>

class AmbiguousIsbnException : public std::exception 
{
    public: 
    const char * what() {
        return "ISBN is not unique";
    }
};