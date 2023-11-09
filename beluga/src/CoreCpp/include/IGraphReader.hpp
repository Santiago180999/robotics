#ifndef IGRAPHREADER
#define IGRAPHREADER
#include <string>
#include "CoreCppTypes.hpp"
namespace CoreCpp
{
    /**
     * @brief Generic Graph Document reader. Extend to json and csv readers
    */
    class IGraphReader
    {
        public:
        /**
         * @brief
        */
        virtual CoreCpp::StatusCode JsonReader() = 0;

        /**
         * @brief
        */
        virtual CoreCpp::StatusCode CsvReader() = 0;

    };
}

#endif