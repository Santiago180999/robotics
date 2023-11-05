/**
 * @brief 
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "IGraph.hpp"
#include "Node.hpp"
#include "CoreCppTypes.hpp"
#include "DocumentReader.hpp"
#include <map>
#include <list>

namespace GraphNs
{
    /**
     * @brief Base graph class 
    */
    class Graph : public GraphNs::IGraph
    {
        public:
        /**
         * @brief Constructs a graph using a file 
        */
        Graph(CoreCpp::DocumentReader& rReader);

        ~Graph() {};

        /**
         * @brief 
        */
        virtual GraphNs::Node* GetNode(int nodeId);

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
        GraphNs::Node* NodeFactory() override; 

        /**
         * @brief Constructs the graph using the content in the file
        */
        CoreCpp::StatusCode BuildGraph() override;

        /**
         * @brief Populates the graph with the content if needed
        */
        virtual CoreCpp::StatusCode PopulateGraph() override;

        /**
         * @brief Draw the graph
        */
        CoreCpp::StatusCode Draw(olc::PixelGameEngine& rEngine) override;
        
        private:
        CoreCpp::DocumentReader& m_rReader;
        int m_numNodes = 0;
        std::map<int, GraphNs::Node*> m_nodes;
        std::map<int, std::vector<int>> m_edges;
    };
}



#endif