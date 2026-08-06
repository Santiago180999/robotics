// implement dijkstras

// need to add cost to go and cost to come for the Solver interface, BFS and DFS can just have zero for both
#ifndef BESTFIRST_SEARCH_HPP
#define BESTFIRST_SEARCH_HPP

#include "Problem/ProblemGenerator.hpp"
#include "GridWorld/Path.hpp"
#include "ISolver.hpp"
#include <memory>

namespace Grid
{
class BestFirstSearch : public ISolver 
{
    struct Point
    {
        Grid::Point wp;
        int c2g; // cost to go
    };
    public:
    BestFirstSearch();

    ~BestFirstSearch();

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