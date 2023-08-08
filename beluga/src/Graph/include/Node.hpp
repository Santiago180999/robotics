/**
 * @brief Implementing class of the INode
*/


#ifndef NODE_HPP
#define NODE_HPP

#include "INode.hpp"
#include "NodeContent.hpp"
#include "CoreCppTypes.hpp"


namespace Graph
{
    /**
     * @brief Class implementing the node interface
    */
    class Node : public Graph::INode
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
        virtual Graph::NodeContent* GetNodeContent();
        
        /**
         * @brief
        */
        virtual CoreCpp::StatusCode SetContent(Graph::NodeContent* pContent);

        virtual std::string ToString();

        private:
        
        int32_t m_id;
        Graph::NodeContent* m_content;

    };
}

#endif