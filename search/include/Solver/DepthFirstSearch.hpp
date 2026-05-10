#ifndef DEPTH_FIRST_SEARCH_HPP
#define DEPTH_FIRST_SEARCH_HPP

#include "Problem/ProblemGenerator.hpp"
#include "GridWorld/Path.hpp"
#include <memory>

class DepthFirstSearch
{
    public:
    DepthFirstSearch(ProblemGenerator& problem);

    ~DepthFirstSearch();

    bool solve();

    Grid::Path* getSolution();

    void SetFinalPathBetween(Grid::Point startPoint, Grid::Point endPoint);

    private:
    std::unique_ptr<Grid::Path> m_path;
    ProblemGenerator& r_problem;

};

#endif  