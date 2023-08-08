/**
 * @brief Class for an edge connecting two nodes (vertices)
*/

#ifndef EDGE_HPP
#define EDGE_HPP

#include "CoreCppTypes.hpp"
#include "EdgeContent.hpp"
#include "Node.hpp"

namespace Graph
{
    /**
     * @brief
    */
    class Edge
    {
        public:
        /**
         * @brief
        */
        Edge(Graph::Node& rNodeA, Graph::Node& rNodeB);

        /**
         * @brief
        */
        std::pair<Graph::Node*, Graph::Node*> GetNodes();

        /**
         * @brief 
        */
        CoreCpp::StatusCode SetContent(Graph::EdgeContent* pContent);
        
        virtual std::string ToString();


        private:
        std::pair<Graph::Node*, Graph::Node*> m_nodes;
        Graph::EdgeContent* m_content;
    };
}


#endif