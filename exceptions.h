
#ifndef _exceptions_h
#define _exceptions_h

#include <stdexcept>

class invalid_params : public std::runtime_error
{
public:
    invalid_params(std::string const& error) : std::runtime_error(error)
    {
    }
    
};

#endif /* _exceptions_h */
