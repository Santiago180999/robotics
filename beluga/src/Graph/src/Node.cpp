#include "Node.hpp"
#include "spdlog/spdlog.h"
namespace GraphNs
{
    Node::Node(int nodeId) : m_id{nodeId}
    {
        // nothing
    }

    INode* Node::GetNode()
    {
        return this;
    }

    int Node::GetId()
    {
        return m_id;
    }

    CoreCpp::StatusCode Node::AddEdge(GraphNs::Edge* newEdge)
    {   
        size_t oldSize = m_edges.size();
        m_edges.push_back(*newEdge);

        if (m_edges.size() > oldSize)
        {
            return CoreCpp::SUCCESS;
        }
        else 
        {
            spdlog::error("failed to add new edge");
            return CoreCpp::Failure;
        }
        
    }

    std::list<GraphNs::Edge> Node::GetEdges()
    {
        return m_edges;
    }

    std::string Node::ToString()
    {
        return std::string("("+ std::to_string(m_id) + ")");
    }
}