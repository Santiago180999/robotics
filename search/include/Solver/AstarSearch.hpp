// implement A Star

// need to add cost to go and cost to come for the Solver interface, BFS and DFS can just have zero for both
#ifndef ASTAR_SEARCH_HPP
#define ASTAR_SEARCH_HPP

#include "Problem/ProblemGenerator.hpp"
#include "GridWorld/Path.hpp"
#include "ISolver.hpp"
#include <memory>

namespace Grid
{
class AstarSearch : public ISolver 
{
    struct Point
    {
        Grid::Point wp;
        int c2c; // cost to come
        int c2g; // cost to go;
    };
    public:
    AstarSearch();

    ~AstarSearch();

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