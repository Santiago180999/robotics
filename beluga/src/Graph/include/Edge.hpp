/**
 * @brief Class for an edge connecting two nodes (vertices)
*/

#ifndef EDGE_HPP
#define EDGE_HPP

#include "CoreCppTypes.hpp"
#include "Node.hpp"
#include "IGraphElement.hpp"

namespace GraphNs
{
    class Node;
    /**
     * @brief
    */
    class Edge : public GraphNs::IGraphElement
    {
        public:
            /**
             * @brief
            */
            Edge(Node* rDest, double cost);

            virtual ~Edge() {};

            /**
             * @brief
            */
            Node* GetDestNode();

            /**
             * @brief
            */
            double GetCost();
         
            /**
             * @brief 
            */
            virtual std::string ToString() override;


        private:
            Node* m_destNode;
            double m_cost;
    };
}


#endif