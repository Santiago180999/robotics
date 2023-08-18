

#ifndef GENERIC_CONTENT_NODE_HPP
#define GENERIC_CONTENT_NODE_HPP

#include "Node.hpp"

class ContentNode : public GraphNs::Node
{
    public:
        ContentNode(int nodeId);
        ContentNode(int nodeId, double x, double y);
        ~ContentNode() override = default;

        CoreCpp::StatusCode GetContent(double &x, double &y);
        CoreCpp::StatusCode SetContent(double x, double y);

        


    private:
        struct TwoDim
        {
            double x, y;
        };
        TwoDim m_content;

};

#endif