#include "Edge.hpp"

namespace Graph
{
    Edge::Edge(Graph::Node& rNodeA, Graph::Node& rNodeB)
    {
        m_nodes = std::make_pair<Graph::Node*, Graph::Node*>(&rNodeA, &rNodeB);
    }

    std::pair<Graph::Node*, Graph::Node*> Edge::GetNodes()
    {
        return m_nodes;
    }

    CoreCpp::StatusCode Edge::SetContent(Graph::EdgeContent* pContent)
    {
        m_content = std::move(pContent);

        // write a check to make sure the content is passed correctly
        return CoreCpp::SUCCESS;
    }

    std::string Edge::ToString()
    {
        std::string NodeA, NodeB;
        NodeA = m_nodes.first->ToString();
        NodeB = m_nodes.second->ToString();

        return NodeA + std::string(" - ") + NodeB + "\n";
    }
}