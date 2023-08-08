/**
 * @brief Implementing class of CoreCpp::IContent, that is wrapper to edge contents like location
*/

#ifndef EDGE_CONTENT_HPP
#define EDGE_CONTENT_HPP

#include "IContent.hpp"
#include "CoreCppTypes.hpp"


namespace Graph
{
    class EdgeContent : public CoreCpp::IContent
    {
        public:
        /**
         * @brief
        */
        EdgeContent() = default;
        /**
         * @brief
        */
        virtual CoreCpp::StatusCode PopulateContent() override;
    };
}

#endif