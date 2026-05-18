#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP

#include "GridWorld/Path.hpp"
#include "Problem/ProblemGenerator.hpp"
#include "ISolver.hpp"
#include <memory>

namespace Grid
{
class BreadthFirstSearch : public ISolver
{
    public:
    BreadthFirstSearch();

    ~BreadthFirstSearch();

    void setProblem(Problem* problem) override;

    bool solve() override;

    Grid::Path* getSolution() override;

    void SetFinalPathBetween(Grid::Point startPoint, Grid::Point endPoint);

    private:
    std::unique_ptr<Grid::Path> m_path;
    Problem* m_problem;
};
}

#endif  