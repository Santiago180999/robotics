#include "GenericContentNode.hpp"

ContentNode::ContentNode(int nodeId) : GraphNs::Node(nodeId)
{
    
}

ContentNode::ContentNode(int nodeId, double x, double y) : GraphNs::Node(nodeId)
{
    m_content.x = x;
    m_content.y = y;
}

CoreCpp::StatusCode ContentNode::GetContent(double &x, double &y)
{
    x = m_content.x;
    y = m_content.y;

    return CoreCpp::SUCCESS;
}

CoreCpp::StatusCode ContentNode::SetContent(double x, double y)
{
    m_content.x = x;
    m_content.y = y;

    return CoreCpp::SUCCESS;
}
