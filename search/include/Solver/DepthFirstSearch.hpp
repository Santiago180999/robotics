#ifndef DEPTH_FIRST_SEARCH_HPP
#define DEPTH_FIRST_SEARCH_HPP

#include "GridWorld/GridWorld.hpp"
#include "GridWorld/Path.hpp"
#include <memory>

class DepthFirstSearch
{
    public:
    DepthFirstSearch(Grid::GridWorld* world);

    ~DepthFirstSearch();

    bool solve(Grid::Point start);

    Grid::Path* getSolution();

    void SetFinalPathBetween(Grid::Point startPoint, Grid::Point endPoint);

    private:
    std::unique_ptr<Grid::Path> m_path;
    Grid::GridWorld* p_world;

};

#endif  