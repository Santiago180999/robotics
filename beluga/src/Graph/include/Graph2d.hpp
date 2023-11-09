#ifndef GRAPH_2D_HPP
#define GRAPH_2D_HPP

#include "IGraph.hpp"
#include "Node2d.hpp"
#include "GraphReader2d.hpp"


namespace GraphNs
{
    class Graph2d : public GraphNs::IGraph
    {
        public:
        Graph2d() = default;

        Graph2d(CoreCpp::GraphReader2d& rReader);

        Graph2d(Graph2d& rGraph);

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
        
        /**
         * @brief Draw the graph, nodes by position and lines by nodes. 
        */
        CoreCpp::StatusCode Draw(olc::PixelGameEngine& rEngine) override;

        /**
         * @brief Depth First Search of the graph
         * @param pEngine - pointer to the engine, if nullptr dont draw. if null ptr draw
        */
        CoreCpp::StatusCode ExploreGraph(int CurrentNode, std::vector<int>& rDiscovered);
        
        /**
         * @brief Draws the edges between the nodes
        */
        CoreCpp::StatusCode DrawEdge(olc::PixelGameEngine& rEngine, int srcNode, int destNode);

        private:
        CoreCpp::GraphReader2d* m_pReader;
        int m_numNodes = 0; 
        std::map<int, GraphNs::Node2d*> m_nodes;
        std::map<int, std::vector<int>> m_edges;

    };
}

#endif