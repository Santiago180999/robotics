

#ifndef CORECPPTYPES_HPP
#define CORECPPTYPES_HPP

#include <string>

namespace CoreCpp
{
    typedef int32_t StatusCode;

    enum ErrorCodes : StatusCode
    {
        Success = 0,
        Information = 1,
        Failure = -1
    };

    constexpr StatusCode SUCCESS = CoreCpp::ErrorCodes::Success;
}



#endif
