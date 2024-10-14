#include "Visitor/GraphBuilderVisitor.hpp"
#include "spdlog/spdlog.h"

namespace GraphNs
{
    CoreCpp::StatusCode GraphBuilderVisitor::VisitGraph2d(Graph2d *graph2d)
    {
        CoreCpp::StatusCode status;
        auto& Nodes = graph2d->GetGraphReader()->m_nodes;
        auto& Edges = graph2d->GetGraphReader()->m_edges;
        int outId;
        for (auto& node : Nodes)
        {
            status = graph2d->AddNode(outId);

            if (outId != std::get<0>(node))
            {
                spdlog::error("Object node id does not match file in node id");
                return CoreCpp::Failure;
            }
            
        }
        if(graph2d->GetGraphSize() == Nodes.size())
        {
            for (auto& edge : Edges)
            {
                status = graph2d->AddEdge(std::get<0>(edge), std::get<1>(edge));
            }
        }
        else 
        {
            spdlog::error("Number of Nodes in file does not match number of nodes read in");
            return CoreCpp::Failure;
        }

        for (auto& node : Nodes)
        {
            int nId = std::get<0>(node);
            GraphNs::Node2d* cNode = graph2d->GetNode(nId);

            status = cNode->SetContent(std::get<1>(node), std::get<2>(node));

            if (status != CoreCpp::SUCCESS)
            {
                spdlog::error("Could not set content");
                return CoreCpp::Failure;
            }  
        }
        return status;
    }
}