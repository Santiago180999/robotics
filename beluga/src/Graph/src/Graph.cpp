#include "Graph.hpp"
#include "spdlog/spdlog.h"

namespace GraphNs
{
    Graph::Graph()
    {
        
    }

    GraphNs::Node Graph::NodeFactory()
    {
        int NodeId = m_numNodes;
        Node* out = new Node(NodeId);
        return *out;
    }

    CoreCpp::StatusCode Graph::AddNode(int& outId)
    {
        size_t oldSize = m_nodes.size();
        m_nodes.push_back(NodeFactory());
        m_numNodes++;

        if (m_nodes.size() > oldSize)
        {
            outId = m_nodes.back().GetId();
            std::pair<int, GraphNs::Node*> newNode = std::make_pair<int, GraphNs::Node*>(m_nodes.back().GetId(), &m_nodes.back());
            m_nodeMap.insert(newNode);
             
            return CoreCpp::SUCCESS;
        }
        else
        {
            spdlog::error("failed to add new node");
            return CoreCpp::Failure;
        } 
    }

    CoreCpp::StatusCode Graph::AddEdge(int source, int dest, double cost)
    {
        CoreCpp::StatusCode status;

        GraphNs::Node *srcNode, *destNode;
        srcNode = m_nodeMap.at(source);
        destNode = m_nodeMap.at(dest);

        status = srcNode->AddEdge(new Edge(destNode, cost));

        return status;
    }

    std::string Graph::ToString()
    {
        std::string out;

        for (auto &node : m_nodes)
        {
            out = out + node.ToString() + ": ";

            for (auto &edge : node.GetEdges())
            {
                out = out + edge.ToString();
            }

            out = out + "\n";
        }

        return out;
    }
}