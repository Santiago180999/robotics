#include "Node2d.hpp"
#include "olcPixelGameEngine.h"
#include "spdlog/spdlog.h"

namespace GraphNs
{
    Node2d::Node2d(int nodeId, float radius) : m_id{nodeId}, m_radius{radius}
    {
        
    }

    Node2d::Node2d(int nodeId, double x, double y, float radius) : m_id{nodeId}, m_radius{radius}
    {
        m_content.x = x;
        m_content.y = y;
    }

    int Node2d::GetId()
    {
        return m_id;
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
    
    std::string Node2d::ToString()
    {
        return std::string("("+ std::to_string(m_id) + ")");
    }

    CoreCpp::StatusCode Node2d::Draw(olc::PixelGameEngine& rEngine)
    {
        olc::vf2d nodePos(m_content.x, m_content.y); 
        rEngine.DrawCircle(nodePos, m_radius);
        return CoreCpp::SUCCESS;
    }
}