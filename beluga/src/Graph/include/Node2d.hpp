#ifndef NODE_2D_HPP
#define NODE_2D_HPP

#include "INode.hpp"


namespace GraphNs
{
    class Node2d : public GraphNs::INode
    {
        public:
        Node2d(int nodeId, float radius = 2);
        
        Node2d(int nodeId, double x, double y, float radius = 2);

        ~Node2d() override = default;

        /**
         * @brief
        */
        int GetId() override;
            
        /**
         * @brief
        */
        CoreCpp::StatusCode GetContent(float &x, float &y);
        
        /**
         * @brief
        */
        CoreCpp::StatusCode SetContent(float x, float y);

        /**
         * @brief 
        */
        std::string ToString() override;

        /**
         * @brief Draw the node based on the 2D position in content. 
        */
       CoreCpp::StatusCode Draw(olc::PixelGameEngine& rEngine) override;
    


        float m_radius;
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