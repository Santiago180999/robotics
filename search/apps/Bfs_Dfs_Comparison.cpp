#include "Visual/SdlEngine.hpp"
#include "Solver/BreadthFirstSearch.hpp"
#include "Solver/DepthFirstSearch.hpp"
#include "Solver/PathFinder.hpp"
#include "Problem/ProblemGenerator.hpp"
#include "GridWorld/ColoredPath.hpp"

const size_t SCREEN_SIZE = 600;
const int GRID_SIZE = 20;

int main(int argc, char* argv[])
{
    // TODO: add a way for the user to set the start and goal states, and have the algorithm re-generate a solution
    // TODO: think how the stuff learnt implementing this can be re-used for the GCS. 
    SdlEngine display("Comparison Of DFS and BFS", SCREEN_SIZE, SCREEN_SIZE);
    
    // TODO: would be cool to get a repeatable world. i think should be possible knowing the seed
    Grid::ProblemParameters params(GRID_SIZE, Grid::MovementType::ORTHOGONAL);
    Grid::ProblemGenerator gen;

    std::unique_ptr<Grid::Problem> problem = gen.generateRandomProblem(params);

    printf("Seed is: %u\n", gen.getSeed());

    Grid::PathFinder planner;
    planner.setProblem(problem.get());

    display.addRenderable(problem->getWorld());
    display.addRenderable(problem.get());

    Grid::BreadthFirstSearch BFS;
    Grid::DepthFirstSearch DFS;

    planner.setSolver(&BFS);
    planner.solve();

    // A legend would be nice to add
    Grid::ColoredPath BFS_soln = Grid::ColoredPath::ColorPathWith(*BFS.getSolution(), Grid::PathColor::GREEN);

    planner.setSolver(&DFS);
    planner.solve();

    Grid::ColoredPath DFS_soln = Grid::ColoredPath::ColorPathWith(*DFS.getSolution(), Grid::PathColor::BLUE);

    display.addRenderable(&BFS_soln);
    display.addRenderable(&DFS_soln);


    display.run();

    return 0;
}