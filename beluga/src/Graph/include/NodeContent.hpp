/**
 * @brief Implementing class of CoreCpp::IContent, that is wrapper to node contents like location
*/

#ifndef NODE_CONTENT_HPP
#define NODE_CONTENT_HPP

#include "IContent.hpp"
#include "CoreCppTypes.hpp"


namespace Graph
{
    class NodeContent : public CoreCpp::IContent
    {
        public:
        /**
         * @brief
        */
        NodeContent() = default;
        /**
         * @brief
        */
        virtual CoreCpp::StatusCode PopulateContent() override;
    };
}

#endif