#include "Graph.hpp"
#include "spdlog/spdlog.h"

namespace GraphNs
{
    Graph::Graph(CoreCpp::DocumentReader& rReader) : m_rReader{rReader}
    {
    }

    Node* Graph::NodeFactory()
    {
        int NodeId = m_numNodes;
        Node* out = new Node(NodeId);
        return out;
    }

    Node* Graph::GetNode(int nodeId)
    {
        return m_nodes.at(nodeId);
    }

    CoreCpp::StatusCode Graph::AddNode(int& outId)
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

    CoreCpp::StatusCode Graph::AddEdge(int source, int dest)
    {
        m_edges[source].push_back(dest);
        return CoreCpp::SUCCESS;
    }

    std::string Graph::ToString()
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

    CoreCpp::StatusCode Graph::BuildGraph()
    {
        CoreCpp::StatusCode status;
        nlohmann::json Nodes = m_rReader.m_doc.at("Nodes");
        nlohmann::json Edges = m_rReader.m_doc.at("Edges");
        int outId;
        for (auto& node : Nodes)
        {
            status = AddNode(outId);

            if (outId != node.at("id"))
            {
                spdlog::error("Object node id does not match file in node id");
                return CoreCpp::Failure;
            }
            
        }
        if(m_numNodes == m_rReader.m_doc.at("NumNodes"))
        {
            for (auto& edge : Edges)
            {
                status = AddEdge(int(edge.at("src")), int(edge.at("dest")));
            }
        }
        else 
        {
            spdlog::error("Number of Nodes in file does not match number of nodes read in");
            return CoreCpp::Failure;
        }
        return status;
    }

    CoreCpp::StatusCode Graph::PopulateGraph()
    {
        // nothing defined at this level
        return CoreCpp::SUCCESS;
    }

    CoreCpp::StatusCode Graph::Draw(olc::PixelGameEngine& rEngine)
    {
        // nothing for now
        return CoreCpp::SUCCESS;
    }

}