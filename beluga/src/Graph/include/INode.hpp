/**
 * @brief Interface class for a node (vertex) of a graph
*/

#ifndef INODE_HPP
#define INODE_HPP

#include <string>
#include "CoreCppTypes.hpp"

namespace GraphNs 
{
    class INode
    {
        public:
        virtual ~INode() {};

        /**
        * @brief Get the pointer to the current node
        */
        virtual INode* GetNode() = 0;

        /**
         * @brief Get the identification of the node
        */
        virtual int GetId() = 0;
    };
}


#endif