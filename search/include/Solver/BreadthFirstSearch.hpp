#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP

#include "GridWorld/GridWorld.hpp"
#include "GridWorld/Path.hpp"
#include <memory>

class BreadthFirstSearch
{
    public:
    BreadthFirstSearch(Grid::GridWorld* world);

    ~BreadthFirstSearch();

    bool solve(Grid::Point start);

    Grid::Path* getSolution();

    void SetFinalPathBetween(Grid::Point startPoint, Grid::Point endPoint);

    private:
    std::unique_ptr<Grid::Path> m_path;
    Grid::GridWorld* p_world;

};

#endif  