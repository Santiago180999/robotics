#include "Solver/PathFinder.hpp"

namespace Grid
{
    void PathFinder::setProblem(Problem* problem)
    {
        this->m_problem = problem;
    }

    void PathFinder::setSolver(ISolver* solver)
    {
        this->m_solver = solver;
    }

    bool PathFinder::solve()
    {
        this->m_solver->setProblem(m_problem);
        return this->m_solver->solve();
    }

    Path* PathFinder::getSolution()
    {
        return this->m_solver->getSolution();
    }



}