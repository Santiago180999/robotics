/**
 * @brief Interface class for a node (vertex) of a graph
*/

#ifndef INODE_HPP
#define INODE_HPP

#include <string>
#include "CoreCppTypes.hpp"

namespace Graph 
{
    class INode
    {
        public:
        INode() = default;

        /**
        * @brief Get the pointer to the current node
        */
        virtual INode* GetNode() = 0;

        /**
         * @brief Get the identification of the node
        */
        virtual int32_t GetId() = 0;

        /**
         * @brief Convert the node to a string representation
        */
        virtual std::string ToString() = 0;
    };
}


#endif