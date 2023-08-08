#include "Edge.hpp"

namespace GraphNs
{
    Edge::Edge(GraphNs::Node& rNodeA, GraphNs::Node& rNodeB)
    {
        m_nodes = std::make_pair<GraphNs::Node*, GraphNs::Node*>(&rNodeA, &rNodeB);
    }

    std::pair<GraphNs::Node*, GraphNs::Node*> Edge::GetNodes()
    {
        return m_nodes;
    }

    CoreCpp::StatusCode Edge::SetContent(GraphNs::EdgeContent* pContent)
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