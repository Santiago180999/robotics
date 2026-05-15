#ifndef DEPTH_FIRST_SEARCH_HPP
#define DEPTH_FIRST_SEARCH_HPP

#include "Problem/ProblemGenerator.hpp"
#include "GridWorld/Path.hpp"
#include "ISolver.hpp"
#include <memory>

namespace Grid
{
class DepthFirstSearch : public ISolver 
{
    public:
    DepthFirstSearch();

    ~DepthFirstSearch();

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