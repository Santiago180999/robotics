/**
 * @brief 
*/

#ifndef IGRAPH_HPP
#define IGRAPH_HPP

#include "INode.hpp"
#include "CoreCppTypes.hpp"
#include "DocumentReader.hpp"
#include <map>
#include <list>

namespace GraphNs
{
    /**
     * @brief Base graph class 
    */
    class IGraph: public IGraphElement
    {
        public:

        virtual ~IGraph() {};

        /**
         * @brief 
        */
        virtual GraphNs::INode* GetNode(int nodeId) = 0;

        /**
         * @brief Creates a new node and adds it to the graph. 
        */
        virtual CoreCpp::StatusCode AddNode(int &outId) = 0; 

        /**
         * @brief Creates a new edge between the given nodes.
        */
        virtual CoreCpp::StatusCode AddEdge(int source, int dest) = 0;

        /**
         * @brief Calls constructor for the required node
        */
        virtual GraphNs::INode* NodeFactory() = 0; 
        
        /**
         * @brief Constructs the graph using the content in the file
        */
        virtual CoreCpp::StatusCode BuildGraph() = 0;

        /**
         * @brief Populates the graph with the content if needed
        */
        virtual CoreCpp::StatusCode PopulateGraph() = 0;
    };
}



#endif