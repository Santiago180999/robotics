/**
 * @brief Interface class for a node (vertex) of a graph
*/

#ifndef INODE_HPP
#define INODE_HPP

#include "IGraphElement.hpp"
#include <string>
#include "CoreCppTypes.hpp"

namespace GraphNs 
{
    class INode: public IGraphElement
    {
        public:
        virtual ~INode() {};

        /**
         * @brief Get the identification of the node
        */
        virtual int GetId() = 0;
    };
}


#endif