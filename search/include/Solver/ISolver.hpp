#ifndef IGRIDSOLVER_HPP
#define IGRIDSOLVER_HPP

#include "GridWorld/Path.hpp"
#include "Problem/Problem.hpp"

namespace Grid
{
    // TODO: Jason suggested to track some metrics
    class ISolver
    {
        public:
        ~ISolver() = default;
        virtual void setProblem(Problem* problem) = 0;
        virtual bool solve() = 0;
        virtual Path* getSolution() = 0;
    };
}


#endif