#ifndef __AMBIGUOUS_EXCEPTION_HEADER__
#define __AMBIGUOUS_EXCEPTION_HEADER__

#include <exception>

class AmbiguousIsbnException : public std::exception 
{
    public: 
    const char * what() {
        return "ISBN is not unique";
    }
};

#endif