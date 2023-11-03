/**
 * @brief Implementing class of the INode
*/


#ifndef NODE_HPP
#define NODE_HPP

#include <list>
#include "INode.hpp"
#include "CoreCppTypes.hpp"
#include "IGraphElement.hpp"


namespace GraphNs
{
    /**
     * @brief Class implementing the node interface
    */
    class Node : public GraphNs::INode
    {
        public:
            Node() = default;
            /**
             * @brief
            */
            Node(int nodeId);

            ~Node() {};

            /**
             * @brief
            */
            int GetId() override;

            /**
             * @brief 
            */
            std::string ToString() override;
            

        private:
            int m_id;

    };
}

#endif