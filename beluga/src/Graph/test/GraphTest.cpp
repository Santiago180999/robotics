
#include "Node.hpp"
#include "spdlog/spdlog.h"
#include "Edge.hpp"
#include "Graph.hpp"
#include "DocumentReader.hpp"
#include "GenericContentGraph.hpp"


// file show how to use the base graph class and the generic content graph class
// the proper creation of a graph depends on the json file to be formatted properly
int main()
{
    // creting basic graph, no content exercises the simple node factory and graph builder
    std::string graphFilePath("/home/santi/dolphin/robotics/beluga/src/Graph/test/testGraph/graph.json");

    CoreCpp::DocumentReader graphJson(graphFilePath);

    GraphNs::Graph graph(graphJson);
    graph.BuildGraph();

    spdlog::info(graph.ToString());

    // creating a generic content graph, exercises the graph builder and populator
    std::string contentGraphFilePath("/home/santi/dolphin/robotics/beluga/src/Graph/test/testGraph/contentGraph.json");
    
    CoreCpp::DocumentReader contentGraphJson(contentGraphFilePath);

    ContentGraph contentGraph(contentGraphJson);
    contentGraph.BuildGraph();

    spdlog::info(contentGraph.ToString());


    // testing getting the content in the node
    ContentNode* node5 = dynamic_cast<ContentNode*>(contentGraph.GetNode(4));
    double x5, y5;
    node5->GetContent(x5, y5);

    spdlog::info(std::to_string(x5));
    spdlog::info(std::to_string(y5));

    return 0;
}