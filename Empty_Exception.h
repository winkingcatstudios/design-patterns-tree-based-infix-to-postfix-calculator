#ifndef _EMPTY_EXCEPTION_
#define _EMPTY_EXCEPTION_

#include <stdexcept>

class Empty_Exception : public std::logic_error
{
public:
    //  Default constructor
    Empty_Exception(void)
        :std::logic_error("") { }

    //  Initializing constructor
    Empty_Exception(const char* msg)
        :std::logic_error(msg) { }
};

#endif