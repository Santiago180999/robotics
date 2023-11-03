#include "Node2d.hpp"
#include "spdlog/spdlog.h"

namespace GraphNs
{
    Node2d::Node2d(int nodeId) : m_id{nodeId}
    {
        
    }

    Node2d::Node2d(int nodeId, double x, double y) : m_id{nodeId}
    {
        m_content.x = x;
        m_content.y = y;
    }

    int Node2d::GetId()
    {
        return m_id;
    }

    std::string Node2d::ToString()
    {
        return std::string("("+ std::to_string(m_id) + ")");
    }

    CoreCpp::StatusCode Node2d::GetContent(float &x, float &y)
    {
        x = m_content.x;
        y = m_content.y;

        return CoreCpp::SUCCESS;
    }

    CoreCpp::StatusCode Node2d::SetContent(float x, float y)
    {
        m_content.x = x;
        m_content.y = y;

        return CoreCpp::SUCCESS;
    }
}