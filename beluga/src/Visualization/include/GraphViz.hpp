#ifndef GRAPH_VIZ_HPP
#define GRAPH_VIZ_HPP

#include "olcPixelGameEngine.h"
#include "Graph2d.hpp"

// Override base class with your custom functionality
class GraphViz : public olc::PixelGameEngine
{
public:
	GraphViz(CoreCpp::DocumentReader& rReader);

	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;

private:
	GraphNs::Graph2d m_graph;

};
#endif
