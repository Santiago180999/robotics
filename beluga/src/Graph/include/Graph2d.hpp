

#ifndef GENERIC_CONTENT_GRAPH_HPP
#define GENERIC_CONTENT_GRAPH_HPP

#include "Graph.hpp"
#include "Node2d.hpp"


namespace GraphNs
{
    class Graph2d : public GraphNs::IGraph
    {
        public:
        Graph2d(CoreCpp::DocumentReader& rReader);

        ~Graph2d() {};

        /**
         * @brief 
        */
        virtual GraphNs::Node2d* GetNode(int nodeId);

        /**
         * @brief Creates a new node and adds it to the graph. 
        */
        CoreCpp::StatusCode AddNode(int &outId) override; 

        /**
         * @brief Creates a new edge between the given nodes.
        */
        CoreCpp::StatusCode AddEdge(int source, int dest) override;

        /**
         * @brief Prints the graph nicely to the terminal
        */
        std::string ToString();

        /**
         * @brief Calls constructor for the required node
        */
        GraphNs::Node2d* NodeFactory() override; 

        /**
         * @brief Constructs the graph using the content in the file
        */
        CoreCpp::StatusCode BuildGraph() override;

        /**
         * @brief Populates the graph with the content if needed
        */
        virtual CoreCpp::StatusCode PopulateGraph() override;
        
        private:
        CoreCpp::DocumentReader& m_rReader;
        int m_numNodes = 0;
        std::map<int, GraphNs::Node2d*> m_nodes;
        std::map<int, std::vector<int>> m_edges;

    };
}

#endif