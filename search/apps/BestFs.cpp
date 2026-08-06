#include "Visual/SdlEngine.hpp"
#include "Solver/PathFinder.hpp"
#include "Solver/BestFirstSearch.hpp"
#include "Problem/ProblemGenerator.hpp"
#include "Visual/PathRenderer.hpp"
#include "GridWorld/PathRenderStrategy.hpp"

const size_t SCREEN_SIZE = 600;
const int GRID_SIZE = 30;

int main(int argc, char* argv[])
{
    Grid::ProblemGenerator gen;
    Grid::PathFinder planner;
    PathRenderer rend;
    std::unique_ptr<Grid::Problem> problem;
    
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

    Grid::BestFirstSearch solver;

    planner.setSolver(&solver);
    planner.solve();

    Grid::DrawPath fin(Grid::PathColor::GREEN);
    Grid::ShowExplorationDecorator dec(Grid::PathColor::EXPLORE, &fin);

    Grid::Path sol = planner.getSolution();
    rend.setPath(&sol);
    rend.setStrategy(&dec);

    SdlEngine display("Best First Search", SCREEN_SIZE, SCREEN_SIZE);
    display.addRenderable(problem->getWorld());
    display.addRenderable(problem.get());
    display.addRenderable(&rend);
    display.run(); 

    return 0;
}