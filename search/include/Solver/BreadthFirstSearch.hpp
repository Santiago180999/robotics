#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP

#include "GridWorld/Path.hpp"
#include "Problem/ProblemGenerator.hpp"
#include <memory>

class BreadthFirstSearch
{
    public:
    BreadthFirstSearch(ProblemGenerator& problem);

    ~BreadthFirstSearch();

    bool solve();

    Grid::Path* getSolution();

    void SetFinalPathBetween(Grid::Point startPoint, Grid::Point endPoint);

    private:
    std::unique_ptr<Grid::Path> m_path;
    ProblemGenerator& r_problem;

};

#endif  