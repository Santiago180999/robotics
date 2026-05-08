#ifndef DEPTH_FIRST_SEARCH_HPP
#define DEPTH_FIRST_SEARCH_HPP

#include "GridWorld/GridWorld.hpp"
#include "GridWorld/Path.hpp"

class DepthFirstSearch
{
    public:
    DepthFirstSearch();

    bool solve(Grid::GridWorld& world, Grid::Point start);

    Grid::Path& getSolution();

    void SetFinalPathBetween(Grid::Point startPoint, Grid::Point endPoint);

    private:
    Grid::Path m_path;
};

#endif  