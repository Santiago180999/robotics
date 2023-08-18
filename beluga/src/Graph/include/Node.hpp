/**
 * @brief Implementing class of the INode
*/


#ifndef NODE_HPP
#define NODE_HPP

#include <list>
#include "INode.hpp"
#include "CoreCppTypes.hpp"
#include "IGraphElement.hpp"
#include "Edge.hpp"



namespace GraphNs
{
    class Edge;
    /**
     * @brief Class implementing the node interface
    */
    class Node : public GraphNs::INode, GraphNs::IGraphElement
    {
        public:
            Node() = default;
            /**
             * @brief
            */
            Node(int nodeId);

            virtual ~Node() {};
            /**
             * @brief
            */
            INode* GetNode() override;
            /**
             * @brief
            */
            int GetId() override;

            /**
             * @brief
            */
            CoreCpp::StatusCode AddEdge(Edge* newEdge);
            /**
             * @brief
            */
            std::list<Edge> GetEdges(); 
            /**
             * @brief 
            */
            std::string ToString() override;
            

        private:
            int m_id;
            std::list<Edge> m_edges;

    };
}

#endif