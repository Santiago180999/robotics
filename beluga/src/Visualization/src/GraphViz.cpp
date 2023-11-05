#include "GraphViz.hpp"
#include "spdlog/spdlog.h"

GraphViz::GraphViz(CoreCpp::DocumentReader& rReader)
{
    // Name your application
    sAppName = "2D Graph Visualization";

    // build graph
    m_graph = GraphNs::Graph2d(rReader);
}

bool GraphViz::OnUserCreate()
{
    // Called once at the start, so create things here
    m_graph.BuildGraph();
    spdlog::info(m_graph.ToString());
    m_graph.Draw(*this);

    return true;
}

bool GraphViz::OnUserUpdate(float fElapsedTime)
{
    return true;
}
