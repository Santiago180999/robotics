
#include "Node.hpp"
#include "spdlog/spdlog.h"
#include "Edge.hpp"
#include "Graph.hpp"

namespace GraphNs
{
    class Graph2d : public Graph
    {
        public:
        Graph2d() = default;

        GraphNs::Node NodeFactory(GraphNs::NodeContent& rParams) override
        {
            
        };

    };

    struct NodeContent2d : public NodeContent
    {
        NodeContent2d(double x, double y);

        double x = 0;
        double y = 0;
    
    };
}

int main()
{
    int32_t id1 = 45;
    int32_t id2 = 56;

    GraphNs::Node node(id1);
    GraphNs::Node node2(id2);

    
    spdlog::info(node.GetId());

    //CoreCpp::StatusCode nCont = node.GetNodeContent()->PopulateContent();

    // if(nCont == CoreCpp::SUCCESS)
    // {
    //     spdlog::info(nCont);
    // }

    GraphNs::Edge edge1(node, node2);

    spdlog::info(edge1.ToString());

    return 0;
}