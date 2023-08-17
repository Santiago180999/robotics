/**
 * @brief 
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Node.hpp"
#include "Edge.hpp"
#include "CoreCppTypes.hpp"
#include "DocumentReader.hpp"
#include <map>
#include <list>

namespace GraphNs
{
    /**
     * @brief Base graph class 
    */
    class Graph : public GraphNs::IGraphElement
    {
        public:
        /**
         * @brief Constructs a graph using a file 
        */
        Graph(CoreCpp::DocumentReader& rReader);

        virtual ~Graph() {};

        /**
         * @brief Creates a new node and adds it to the graph. 
        */
        CoreCpp::StatusCode AddNode(int &outId); 

        /**
         * @brief Creates a new edge between the given nodes.
        */
        CoreCpp::StatusCode AddEdge(int source, int dest, double cost=0);

        /**
         * @brief Prints the graph nicely to the terminal
        */
        std::string ToString();

        /**
         * @brief Calls constructor for the required node
        */
        virtual GraphNs::Node* NodeFactory(); 
        /**
         * @brief Constructs the graph using the content in the file
        */
        virtual CoreCpp::StatusCode BuildGraph();
        
        protected:
        CoreCpp::DocumentReader& m_rReader;
        int m_numNodes = 0;
        std::list<GraphNs::Node*> m_nodes;
        std::map<int, GraphNs::Node*> m_nodeMap;
    };
}



#endif