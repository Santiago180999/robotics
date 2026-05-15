// strategy implementation of the search algorithms

#ifndef PATHFINDER_HPP
#define PATHFINDER_HPP

#include "ISolver.hpp"
#include "Problem/Problem.hpp"

namespace Grid
{
    class PathFinder
    {
        public:
        PathFinder() = default;

        void setProblem(Problem* problem);

        void setSolver(ISolver* solver);

        bool solve();

        Path getSolution();

        private:
        ISolver* m_solver = nullptr;
        Problem* m_problem = nullptr;
    };
}

#endif 