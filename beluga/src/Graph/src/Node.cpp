#include "Node.hpp"

namespace Graph
{
    Node::Node(int32_t nodeId) : m_id{nodeId}
    {
        // nothing
    }

    INode* Node::GetNode()
    {
        return this;
    }

    int32_t Node::GetId()
    {
        return m_id;
    }

    Graph::NodeContent* Node::GetNodeContent()
    {
        return m_content;
    }

    CoreCpp::StatusCode Node::SetContent(Graph::NodeContent* pContent)
    {
        m_content = std::move(pContent);

        return CoreCpp::SUCCESS;
    }

    std::string Node::ToString()
    {
        return std::string("("+ std::to_string(m_id) + ")");
    }
}