#include "Graph2d.hpp"
#include "spdlog/spdlog.h"
#include "olcPixelGameEngine.h"
#include <iostream>

namespace GraphNs
{
    Graph2d::Graph2d(CoreCpp::GraphReader2d& rReader) : m_pReader{&rReader}
    {
    }

    Graph2d::Graph2d(Graph2d& rGraph) : 
        m_numNodes{rGraph.m_numNodes}, 
        m_nodes{rGraph.m_nodes},
        m_edges{rGraph.m_edges}
    {
    }

    Node2d* Graph2d::NodeFactory()
    {
        int NodeId = m_numNodes;
        Node2d* out = new Node2d(NodeId);
        return out;
    }

    Node2d* Graph2d::GetNode(int nodeId)
    {
        return m_nodes.at(nodeId);
    }

    CoreCpp::StatusCode Graph2d::AddNode(int& outId)
    {
        int oldSize = m_nodes.size();
        m_nodes[m_numNodes] = NodeFactory();

        if (m_nodes.size() > oldSize)
        {
            outId = m_numNodes;
            m_edges[m_numNodes] = std::vector<int>();
            m_numNodes++;
            return CoreCpp::SUCCESS;
        }
        else
        {
            spdlog::error("failed to add new node");
            return CoreCpp::Failure;
        } 
    }

    CoreCpp::StatusCode Graph2d::AddEdge(int source, int dest)
    {
        size_t bef = m_edges[source].size();
        m_edges[source].push_back(dest);
        if (m_edges[source].size() > bef)
        {
            return CoreCpp::SUCCESS;
        }
        else 
        {
            spdlog::error("failed to add new edge");
            return CoreCpp::Failure;
        }
    }

    std::string Graph2d::ToString()
    {
        std::string out = "\n";
        int src, dest;
        for (auto &edge : m_edges)
        {
            src = edge.first;
            for (auto& targ : edge.second)
            {
                dest = targ;
                out = out + "[" + "(" + std::to_string(src) + ")" + " - " + "(" + std::to_string(targ) + ")" + "]\n";
            }
        }

        return out;
    }

    // come back to improve this when visitor pattern is working
    CoreCpp::StatusCode Graph2d::BuildGraph()
    {
        CoreCpp::StatusCode status;
        auto& Nodes = m_pReader->m_nodes;
        auto& Edges = m_pReader->m_edges;
        int outId;
        for (auto& node : Nodes)
        {
            status = AddNode(outId);

            if (outId != std::get<0>(node))
            {
                spdlog::error("Object node id does not match file in node id");
                return CoreCpp::Failure;
            }
            
        }
        if(m_numNodes == Nodes.size())
        {
            for (auto& edge : Edges)
            {
                status = AddEdge(std::get<0>(edge), std::get<1>(edge));
            }
        }
        else 
        {
            spdlog::error("Number of Nodes in file does not match number of nodes read in");
            return CoreCpp::Failure;
        }

        status = PopulateGraph();

        return status;
    }

    CoreCpp::StatusCode Graph2d::PopulateGraph()
    {
        CoreCpp::StatusCode status;
        auto& Nodes = m_pReader->m_nodes;
        auto& Edges = m_pReader->m_edges;

        for (auto& node : Nodes)
        {
            int nId = std::get<0>(node);
            GraphNs::Node2d* cNode = m_nodes.at(nId);

            status = cNode->SetContent(std::get<1>(node), std::get<2>(node));

            if (status != CoreCpp::SUCCESS)
            {
                spdlog::error("Could not set content");
                return CoreCpp::Failure;
            }  
            
        }
        return status;
    }

    CoreCpp::StatusCode Graph2d::Draw(olc::PixelGameEngine& rEngine)
    {
        CoreCpp::StatusCode status;
        int dest;
        // drawing the graph is easy, loop thru all the nodes
        for(auto& src : m_nodes)
        {
            status = src.second->Draw(rEngine);
            for(auto& dest : m_edges[src.first])
            {
                status = DrawEdge(rEngine, src.first, dest);
            }
        }

        

        
        return status;
    }

    CoreCpp::StatusCode Graph2d::DrawEdge(olc::PixelGameEngine& rEngine, int srcNode, int destNode)
    {

        float srcX, srcY, destX, destY, m1, m2, c2c, a, b, r1, r2;

        m_nodes[srcNode]->GetContent(srcX, srcY);
        m_nodes[destNode]->GetContent(destX, destY);

        // find direction of line and length of full line
        a = destX - srcX;
        b = destY - srcY;
        c2c = std::sqrt(a*a + b*b);

        // get radius
        r1 = m_nodes[srcNode]->m_radius;
        r2 = m_nodes[destNode]->m_radius;
        // draw line from edge of circle to edge of circle
        m1 = r1/c2c;
        m2 = r2/c2c;
        olc::vf2d lineStart((1-m1)*srcX+(m1)*destX, (1-m1)*srcY+(m1)*destY); 
        olc::vf2d lineEnd((1-m2)*destX+(m2)*srcX, (1-m2)*destY+(m2)*srcY); 

        rEngine.DrawLine(lineStart, lineEnd);

        return CoreCpp::SUCCESS;

    }

    // bit weird bc itll explore it, but not return anything... i.e wont be able to draw as it searches
    CoreCpp::StatusCode Graph2d::ExploreGraph(int CurrentNode, std::vector<int>& rDiscovered)
    {
        // Depth first search 
       
        // mark as discoverd
        rDiscovered.push_back(CurrentNode);
        for (auto& dest : m_edges[CurrentNode])
        {
            if(std::find(rDiscovered.begin(), rDiscovered.end(), dest) == rDiscovered.end())
            {
                ExploreGraph(dest, rDiscovered);    
            }
        }
        
        return CoreCpp::SUCCESS;

    }
}