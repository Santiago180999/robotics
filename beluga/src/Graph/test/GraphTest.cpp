
#include "Node.hpp"
#include "spdlog/spdlog.h"
#include "Edge.hpp"
#include "Graph.hpp"
#include "DocumentReader.hpp"
//#include "GenericContentGraph.hpp"

int main()
{
/*     GraphNs::Graph graph;

    int NodeIdA;
    graph.AddNode(NodeIdA);
    int NodeIdB;
    graph.AddNode(NodeIdB);
    int NodeIdC;
    graph.AddNode(NodeIdC);
    int NodeIdD;
    graph.AddNode(NodeIdD);

    graph.AddEdge(NodeIdA, NodeIdB, 0);
    graph.AddEdge(NodeIdB, NodeIdC, 21.0);
    graph.AddEdge(NodeIdA, NodeIdD, 52.0); */

    std::string graphFilePath("/home/santi/dolphin/robotics/beluga/src/Graph/test/testGraph/graph.json");

    CoreCpp::DocumentReader graphJson(graphFilePath);

    GraphNs::Graph graph(graphJson);

    spdlog::info(graph.ToString());

/*     ContentGraph genericGraph;
    genericGraph.AddNode(NodeIdA);
    genericGraph.AddNode(NodeIdB);
    genericGraph.AddNode(NodeIdC);
    genericGraph.AddNode(NodeIdD);

    genericGraph.AddEdge(NodeIdA, NodeIdB, 0);
    genericGraph.AddEdge(NodeIdB, NodeIdC, 15.0);
    genericGraph.AddEdge(NodeIdA, NodeIdD, 21.0);

    spdlog::info(genericGraph.ToString()); */

    return 0;
}