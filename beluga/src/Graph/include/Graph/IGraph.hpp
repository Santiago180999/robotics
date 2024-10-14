/**
 * @brief 
*/

#ifndef IGRAPH_HPP
#define IGRAPH_HPP

#include "Node/INode.hpp"
#include "CoreCppTypes.hpp"
#include "olcPixelGameEngine.h"
#include "Visitor/IGraphVisitor.hpp"
#include <map>
#include <list>
namespace GraphNs
{
    class IGraphVisitor;
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
         * @brief Accepts the visitor passed in 
        */
        virtual CoreCpp::StatusCode Accept(IGraphVisitor& visitor) = 0;

        /**
         * @brief Get the graph size
        */
        virtual int GetGraphSize() = 0;

        /**
         * @brief Calls constructor for the required node
        */
        virtual GraphNs::INode* NodeFactory() = 0; 
    };
}



#endif