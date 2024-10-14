#ifndef GRAPH_BUILDER_VISITOR_HPP
#define GRAPH_BUILDER_VISITOR_HPP

#include "IGraphVisitor.hpp"
#include "GraphReader2d.hpp"

namespace GraphNs
{
    class GraphBuilderVisitor: public IGraphVisitor
    {        
        public:
        GraphBuilderVisitor() = default;

        CoreCpp::StatusCode VisitGraph2d(Graph2d *graph2d) override;
    };
} 
#endif