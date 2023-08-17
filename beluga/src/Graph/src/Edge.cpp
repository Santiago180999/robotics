#include "Edge.hpp"

namespace GraphNs
{
    Edge::Edge(GraphNs::Node* rDest, double cost) : m_destNode{rDest}, m_cost{cost}
    {

    }

    GraphNs::Node* Edge::GetDestNode()
    {
        return m_destNode;
    }

    double Edge::GetCost()
    {
        return m_cost;
    }

    std::string Edge::ToString()
    {   
        if (m_cost == 0)
        {
            return std::string(" - ") + m_destNode->ToString();
        }
        else return std::string(" - ") + std::to_string(m_cost) + std::string(" - ") + m_destNode->ToString();
    }
}