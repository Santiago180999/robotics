/**
 * @brief 
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Node.hpp"
#include "Edge.hpp"
#include <map>
#include <vector>

namespace GraphNs
{
    /**
     * @brief
    */
    class Graph
    {
        public:
        Graph();

        virtual GraphNs::Node NodeFactory(GraphNs::NodeContent& rParams) = 0; 

        private:
        std::map<GraphNs::Node*, std::vector<GraphNs::Node*>> m_adjNodes;
        std::vector<GraphNs::Edge*> m_edges;

    };
}



#endif