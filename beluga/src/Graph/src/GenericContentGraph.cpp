#include "GenericContentGraph.hpp"

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

        if (outId != node)
        {
            spdlog::error("Object node id does not match file in node id");
            return CoreCpp::Failure;
        }
        
    }
    if(m_numNodes == m_rReader.m_doc.at("NumNodes"))
    {
        for (auto& edge : Edges)
        {
            status = AddEdge(edge[0], edge[1]);
        }
    }
    else 
    {
        spdlog::error("Number of Nodes in file does not match number of nodes read in");
        return CoreCpp::Failure;
    }
    return status;
}
}