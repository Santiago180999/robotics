

#ifndef GENERIC_CONTENT_GRAPH_HPP
#define GENERIC_CONTENT_GRAPH_HPP

#include "Graph.hpp"
#include "GenericContentNode.hpp"

class ContentGraph : public GraphNs::Graph
{
    public:
    ContentGraph(CoreCpp::DocumentReader& rReader);

    ~ContentGraph() override {};

    GraphNs::Node* NodeFactory() override; 

    CoreCpp::StatusCode BuildGraph() override;

};

#endif