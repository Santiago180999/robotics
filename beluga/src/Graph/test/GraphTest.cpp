
#include "Node.hpp"
#include "spdlog/spdlog.h"
#include "Edge.hpp"
#include "Graph.hpp"

int main()
{
    GraphNs::Graph graph;

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
    graph.AddEdge(NodeIdA, NodeIdD, 52.0);

    spdlog::info(graph.ToString());

    return 0;
}