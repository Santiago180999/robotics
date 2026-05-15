#ifndef PROBLEM_GEN_HPP
#define PROBLEM_GEN_HPP

#include "GridWorld/Generator.hpp"
#include "Problem.hpp"

namespace Grid
{
struct ProblemParameters
{
    ProblemParameters() = default;

    ProblemParameters(size_t size, Grid::MovementType moveType) : size(size), moveType(moveType){}

    ProblemParameters(size_t size, Grid::MovementType moveType, Point startState, Point goalState, uint seed) :
        size(size), moveType(moveType), startState(startState), goalState(goalState), seed(seed){}
    
    size_t size = 20;
    Grid::MovementType moveType = Grid::MovementType::ORTHOGONAL;
    Point startState = {-1, -1};
    Point goalState = {-1, -1};;
    uint seed = std::mt19937::default_seed;
};

class ProblemGenerator
{
    public:
    ProblemGenerator()
    {
        m_problem = std::make_unique<Problem>();
    };

    ~ProblemGenerator() = default;

    std::unique_ptr<Grid::Problem> generateRandomProblem(ProblemParameters& worldParams); // doesnt use the seed or start/end states

    std::unique_ptr<Grid::Problem> generateSpecificProblem(ProblemParameters& worldParams); // uses the specified seed and the start/end states

    std::unique_ptr<Grid::Problem> getProblem();

    uint getSeed();
  
    
    private:
    // generate world
    void generateWorld(size_t size, Grid::MovementType moveType);

    // variables
    Grid::Generator m_generator;
    std::unique_ptr<Grid::Problem> m_problem; 
};
}

#endif  