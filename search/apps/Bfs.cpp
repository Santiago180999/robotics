#include "Visual/SdlEngine.hpp"
#include "Solver/PathFinder.hpp"
#include "Solver/BreadthFirstSearch.hpp"
#include "Problem/ProblemGenerator.hpp"

const size_t SCREEN_SIZE = 600;
const int GRID_SIZE = 20;

int main(int argc, char* argv[])
{
    Grid::ProblemGenerator gen;
    Grid::PathFinder planner;
    std::unique_ptr<Grid::Problem> problem;
    SdlEngine display("Breadth First Search", SCREEN_SIZE, SCREEN_SIZE);
    if (argc < 2)
    {
        Grid::ProblemParameters params(GRID_SIZE, Grid::MovementType::ORTHOGONAL);
    
        
        problem = gen.generateRandomProblem(params);
        printf("Seed is: %u\n", gen.getSeed());
        planner.setProblem(problem.get());
    }
    else
    {
        Grid::Point s = {1,1}; // temp
        Grid::Point g = {1,1}; // temp
        Grid::ProblemParameters params(GRID_SIZE, Grid::MovementType::ORTHOGONAL, s, g, atoi(argv[1]));
        
        problem = gen.generateSpecificProblem(params);
        printf("Seed is: %u\n", gen.getSeed());
        planner.setProblem(problem.get());
    }

    Grid::BreadthFirstSearch solver;

    planner.setSolver(&solver);
    planner.solve();

    display.addRenderable(problem->getWorld());
    display.addRenderable(problem.get());
    display.addRenderable(planner.getSolution());
    display.run(); 

    return 0;
}