#include "Graph.hpp"
#include "spdlog/spdlog.h"

namespace GraphNs
{
    Graph::Graph(CoreCpp::DocumentReader& rReader) : m_rReader{rReader}
    {
    }

    GraphNs::Node* Graph::NodeFactory()
    {
        int NodeId = m_numNodes;
        Node* out = new Node(NodeId);
        return out;
    }

    GraphNs::Node* Graph::GetNode(int nodeId)
    {
        return m_nodeMap.at(nodeId);
    }


    CoreCpp::StatusCode Graph::AddNode(int& outId)
    {
        size_t oldSize = m_nodes.size();
        m_nodes.push_back(NodeFactory());
        m_numNodes++;

        if (m_nodes.size() > oldSize)
        {
            outId = m_nodes.back()->GetId();
            std::pair<int, GraphNs::Node*> newNode = std::make_pair<int, GraphNs::Node*>(m_nodes.back()->GetId(), &(*m_nodes.back()));
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
        std::string out = "\n";

        for (auto &node : m_nodes)
        {
            for (auto &edge : node->GetEdges())
            {
                out = out + "[" + node->ToString() + edge.ToString() + "]\n";
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
                status = AddEdge(edge.at("src"), edge.at("dest"), edge.at("cost"));
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
}