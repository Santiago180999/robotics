

#ifndef GENERIC_CONTENT_GRAPH_HPP
#define GENERIC_CONTENT_GRAPH_HPP

#include "Graph.hpp"
#include "GenericContentNode.hpp"

class ContentGraph : public GraphNs::Graph
{
    public:
    ContentGraph(CoreCpp::DocumentReader& rReader);

    ~ContentGraph() override = default;

    GraphNs::Node* NodeFactory() override; 

    CoreCpp::StatusCode BuildGraph() override;


    CoreCpp::StatusCode PopulateGraph() override;

};

#endif