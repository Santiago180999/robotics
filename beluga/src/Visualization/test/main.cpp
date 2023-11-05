#include "GraphViz.hpp"

int main()
{
	// creating a generic content graph, exercises the graph builder and populator
    std::string Graph2dFilePath("/home/santi/dolphin/robotics/beluga/src/Graph/test/testGraph/Graph2d.json");
    
    CoreCpp::DocumentReader Graph2dJson(Graph2dFilePath);
	GraphViz demo(Graph2dJson);
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}