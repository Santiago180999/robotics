#ifndef GRAPH_VIZ_HPP
#define GRAPH_VIZ_HPP

#include "olcPixelGameEngine.h"
#include "Graph2d.hpp"
#include "GraphReader2d.hpp"

// Override base class with your custom functionality
class GraphViz : public olc::PixelGameEngine
{
public:
	GraphViz(CoreCpp::GraphReader2d& rReader);

	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;

	GraphNs::Graph2d m_graph;

};
#endif
