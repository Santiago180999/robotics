

#ifndef ICONTENT_HPP
#define ICONTENT_HPP

#include "CoreCppTypes.hpp"

namespace CoreCpp
{
    /**
     * @brief Interface class for a wrapper for primitive data
    */
    class IContent
    {
        public:
        /**
         * @brief Default constructor and destructor
        */
        IContent() = default;
        /**
         * @brief Function to populate the data
        */
        virtual CoreCpp::StatusCode PopulateContent() = 0;

        /* Inherting classes should define a public struct that contains the data */
    };
}


#endif