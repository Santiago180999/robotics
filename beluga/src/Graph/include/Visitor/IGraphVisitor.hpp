#ifndef I_GRAPH_VISITOR_HPP
#define I_GRAPH_VISITOR_HPP

/**
 * Implement here the graph builder as a visitor 
*/

#include "Graph/Graph2d.hpp"

namespace GraphNs
{
    class Graph2d;
    class IGraphVisitor
    {
        public:

        virtual CoreCpp::StatusCode VisitGraph2d(Graph2d *graph2d) = 0;
    };
}



#endif