#include "GenericContentGraph.hpp"
#include "spdlog/spdlog.h"
ContentGraph::ContentGraph(CoreCpp::DocumentReader& rReader) : Graph(rReader)
{
}

GraphNs::Node* ContentGraph::NodeFactory()
{
    int NodeId = m_numNodes;
    GraphNs::Node* out = new ContentNode(NodeId);
    return out;
}

CoreCpp::StatusCode ContentGraph::BuildGraph()
{
    CoreCpp::StatusCode status;
    nlohmann::json Nodes = m_rReader.m_doc.at("Nodes");
    nlohmann::json Edges = m_rReader.m_doc.at("Edges");
    int outId;
    for (auto& node : Nodes)
    {
        status = AddNode(outId);

        if (outId != node.at("id"))
        {
            spdlog::error("Object node id does not match file in node id");
            return CoreCpp::Failure;
        }
        
    }
    if(m_numNodes == m_rReader.m_doc.at("NumNodes"))
    {
        for (auto& edge : Edges)
        {
            status = AddEdge(edge.at("src"), edge.at("dest"), edge.at("cost"));
        }
    }
    else 
    {
        spdlog::error("Number of Nodes in file does not match number of nodes read in");
        return CoreCpp::Failure;
    }

    status = PopulateGraph();

    return status;
}

CoreCpp::StatusCode ContentGraph::PopulateGraph()
{
    CoreCpp::StatusCode status;
    nlohmann::json Nodes = m_rReader.m_doc.at("Nodes");
    nlohmann::json Edges = m_rReader.m_doc.at("Edges");

    for (auto& node : Nodes)
    {
        int nId = node.at("id");
        GraphNs::Node* oNode = m_nodeMap.at(nId);
        ContentNode* cNode =  dynamic_cast<ContentNode*>(oNode);

        if(cNode != nullptr)
        {
            status = cNode->SetContent(node.at("x"), node.at("y"));

            if (status != CoreCpp::SUCCESS)
            {
                spdlog::error("Could not set content");
                return CoreCpp::Failure;
            }  
        }
        else
        {
            spdlog::error("could not cast Node to ContentNode");
            return CoreCpp::Failure;
        }
        
    }
    return status;
}
