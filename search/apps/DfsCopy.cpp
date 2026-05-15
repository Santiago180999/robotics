#include "Visual/SdlEngine.hpp"
#include "Solver/PathFinder.hpp"
#include "Solver/DepthFirstSearch.hpp"
#include "Problem/ProblemGenerator.hpp"
#include <stdio.h>

const size_t SCREEN_SIZE = 600;
const int GRID_SIZE = 20;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("you must specify the seed you want to use!\n");
        return 0;
    }
    SdlEngine display("Depth First Search - Explore", SCREEN_SIZE, SCREEN_SIZE);
    
    Grid::Point s = {1,1};
    Grid::Point g = {1,1};
    // example test of recreating a problem w the seed. 
    Grid::ProblemParameters params(GRID_SIZE, Grid::MovementType::ORTHOGONAL, s, g, atoi(argv[1]));
    
    Grid::ProblemGenerator gen;
    
    std::unique_ptr<Grid::Problem> problem = gen.generateSpecificProblem(params);

    printf("Seed is: %u\n", gen.getSeed());
    
    Grid::PathFinder planner;

    planner.setProblem(problem.get());

    Grid::DepthFirstSearch solver;

    planner.setSolver(&solver);
    planner.solve();

    display.addRenderable(problem->getWorld());
    display.addRenderable(problem.get());
    display.addRenderable(planner.getSolution()); // how can i superimpose various paths?
    display.run(); 

    return 0;
}