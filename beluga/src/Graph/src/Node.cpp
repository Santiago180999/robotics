#include "Node.hpp"
#include "spdlog/spdlog.h"
namespace GraphNs
{
    Node::Node(int nodeId) : m_id{nodeId}
    {
        // nothing
    }

    int Node::GetId()
    {
        return m_id;
    }

    std::string Node::ToString()
    {
        return std::string("("+ std::to_string(m_id) + ")");
    }
}