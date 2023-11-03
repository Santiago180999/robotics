#include "Graph2d.hpp"
#include "spdlog/spdlog.h"
#include <iostream>
namespace GraphNs
{
    Graph2d::Graph2d(CoreCpp::DocumentReader& rReader) : m_rReader{rReader}
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
        m_edges[source].push_back(dest);
        return CoreCpp::SUCCESS;
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


    CoreCpp::StatusCode Graph2d::BuildGraph()
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

        status = PopulateGraph();

        return status;
    }

    CoreCpp::StatusCode Graph2d::PopulateGraph()
    {
        CoreCpp::StatusCode status;
        nlohmann::json Nodes = m_rReader.m_doc.at("Nodes");
        nlohmann::json Edges = m_rReader.m_doc.at("Edges");

        for (auto& node : Nodes)
        {
            int nId = node.at("id");
            GraphNs::Node2d* cNode = m_nodes.at(nId);

            status = cNode->SetContent(node.at("x"), node.at("y"));

            if (status != CoreCpp::SUCCESS)
            {
                spdlog::error("Could not set content");
                return CoreCpp::Failure;
            }  
            
        }
        return status;
    }
}