#ifndef NODE_2D_HPP
#define NODE_2D_HPP

#include "Node.hpp"


namespace GraphNs
{
    class Edge;

    class Node2d : public GraphNs::INode
    {
        public:
        Node2d(int nodeId);
        
        Node2d(int nodeId, double x, double y);

        ~Node2d() override = default;

        /**
         * @brief
        */
        int GetId() override;

        /**
         * @brief 
        */
        std::string ToString() override;
            
        /**
         * @brief
        */
        CoreCpp::StatusCode GetContent(float &x, float &y);
        
        /**
         * @brief
        */
        CoreCpp::StatusCode SetContent(float x, float y);

        
    private:
        int m_id;

        struct TwoDim
        {
            float x, y;
        };
        TwoDim m_content;


    };
}

#endif