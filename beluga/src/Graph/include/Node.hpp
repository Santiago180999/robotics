/**
 * @brief Implementing class of the INode
*/


#ifndef NODE_HPP
#define NODE_HPP

#include "INode.hpp"
#include "NodeContent.hpp"
#include "CoreCppTypes.hpp"


namespace GraphNs
{
    /**
     * @brief Class implementing the node interface
    */
    class Node : public GraphNs::INode
    {
        public:
        /**
         * @brief
        */
        Node(int32_t nodeId);
        /**
         * @brief
        */
        virtual INode* GetNode() override;
        /**
         * @brief
        */
        virtual int32_t GetId() override;
        /**
         * @brief
        */
        virtual GraphNs::NodeContent* GetNodeContent();
        
        /**
         * @brief
        */
        virtual CoreCpp::StatusCode SetContent(GraphNs::NodeContent* pContent);

        virtual std::string ToString();

        private:
        
        int32_t m_id;
        GraphNs::NodeContent* m_content;

    };
}

#endif