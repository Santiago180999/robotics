#include "GraphViz.hpp"
#include "spdlog/spdlog.h"

GraphViz::GraphViz(CoreCpp::GraphReader2d& rReader)
{
    // Name your application
    sAppName = "2D Graph Visualization";

    // build graph
    m_graph = GraphNs::Graph2d(rReader);
    m_graph.BuildGraph();
    spdlog::info(m_graph.ToString());
}

bool GraphViz::OnUserCreate()
{
    // Called once at the start, so create things here
    
    m_graph.Draw(*this);

    return true;
}

bool GraphViz::OnUserUpdate(float fElapsedTime)
{
    return true;
}

int main()
{
	// creating a generic content graph, exercises the graph builder and populator
    std::string Graph2dFilePath("/home/santi/robotics/beluga/src/Graph/test/testGraph/Graph2d.json");
    
    CoreCpp::GraphReader2d Graph2dJson(Graph2dFilePath, false);
	GraphViz demo(Graph2dJson);

	if (demo.Construct(256, 240, 4, 4))
		demo.Start();

	std::vector<int> dfs;

	int node = 0;
	demo.m_graph.ExploreGraph(node, dfs);
	std::string bit("\n");
	for(auto& k : dfs)
	{
		bit = bit + std::to_string(k) + "\n";
	}
	spdlog::info(bit);
	
	return 0;
}