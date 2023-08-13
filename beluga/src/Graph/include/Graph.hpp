/**
 * @brief 
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Node.hpp"
#include "Edge.hpp"
#include "CoreCppTypes.hpp"
#include <map>
#include <list>

namespace GraphNs
{
    /**
     * @brief
    */
    class Graph : public GraphNs::IGraphElement
    {
        public:

        Graph();

        virtual ~Graph() {};

        CoreCpp::StatusCode AddNode(int& outId); 

        CoreCpp::StatusCode AddEdge(int source, int dest, double cost);

        std::string ToString();

        protected:
        virtual GraphNs::Node NodeFactory(); 

        private:
        int m_numNodes = 0;
        std::list<GraphNs::Node> m_nodes;
        std::map<int, GraphNs::Node*> m_nodeMap;
        

    };
}



#endif