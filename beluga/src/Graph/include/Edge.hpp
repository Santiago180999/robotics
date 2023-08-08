/**
 * @brief Class for an edge connecting two nodes (vertices)
*/

#ifndef EDGE_HPP
#define EDGE_HPP

#include "CoreCppTypes.hpp"
#include "EdgeContent.hpp"
#include "Node.hpp"

namespace GraphNs
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
        Edge(GraphNs::Node& rNodeA, GraphNs::Node& rNodeB);

        /**
         * @brief
        */
        std::pair<GraphNs::Node*, GraphNs::Node*> GetNodes();

        /**
         * @brief 
        */
        CoreCpp::StatusCode SetContent(GraphNs::EdgeContent* pContent);
        
        virtual std::string ToString();


        private:
        std::pair<GraphNs::Node*, GraphNs::Node*> m_nodes;
        GraphNs::EdgeContent* m_content;
    };
}


#endif