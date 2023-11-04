

#ifndef CORECPPTYPES_HPP
#define CORECPPTYPES_HPP

#include <string>

namespace CoreCpp
{
    typedef int StatusCode;

    enum ErrorCodes : StatusCode
    {
        Advance = 0,
        Information = 1,
        Failure = -1
    };

    constexpr StatusCode SUCCESS = CoreCpp::ErrorCodes::Advance;
}



#endif
