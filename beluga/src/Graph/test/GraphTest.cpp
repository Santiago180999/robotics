
#include "Node.hpp"
#include "spdlog/spdlog.h"
#include "Edge.hpp"

int main()
{
    int32_t id1 = 45;
    int32_t id2 = 56;

    Graph::Node node(id1);
    Graph::Node node2(id2);

    
    spdlog::info(node.GetId());

    //CoreCpp::StatusCode nCont = node.GetNodeContent()->PopulateContent();

    // if(nCont == CoreCpp::SUCCESS)
    // {
    //     spdlog::info(nCont);
    // }

    Graph::Edge edge1(node, node2);

    spdlog::info(edge1.ToString());

    return 0;
}