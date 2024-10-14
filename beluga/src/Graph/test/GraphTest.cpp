
#include "spdlog/spdlog.h"
#include "Visitor/GraphBuilderVisitor.hpp"
#include "Graph/Graph2d.hpp"
#include "GraphReader2d.hpp"


// file show how to use the base graph class and the generic content graph class
// the proper creation of a graph depends on the json file to be formatted properly
int main()
{
    // creating a generic content graph, exercises the graph builder and populator
    std::string Graph2dFilePath("/home/santi/robotics/beluga/src/Graph/test/testGraph/Graph2d.csv");
    
    CoreCpp::GraphReader2d Graph2dJson(Graph2dFilePath, true);

    GraphNs::Graph2d Graph2d(Graph2dJson);
    GraphNs::GraphBuilderVisitor Builder;
    // build the graph
    Graph2d.Accept(Builder);

    spdlog::info(Graph2d.ToString());


    // testing getting the content in the node
    GraphNs::Node2d* node5 = Graph2d.GetNode(4);
    float x5, y5;
    node5->GetContent(x5, y5);

    spdlog::info(std::to_string(x5));
    spdlog::info(std::to_string(y5));

    return 0;
}