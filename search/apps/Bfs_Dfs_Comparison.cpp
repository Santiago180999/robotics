#include "Visual/SdlEngine.hpp"
#include "Solver/BreadthFirstSearch.hpp"
#include "Solver/DepthFirstSearch.hpp"
#include "Solver/PathFinder.hpp"
#include "Problem/ProblemGenerator.hpp"
#include "Visual/PathRenderer.hpp"
#include "GridWorld/PathRenderStrategy.hpp"

const size_t SCREEN_SIZE = 600;
const int GRID_SIZE = 20;

int main(int argc, char* argv[])
{
    // TODO: add a way for the user to set the start and goal states, and have the algorithm re-generate a solution
    // TODO: think how the stuff learnt implementing this can be re-used for the GCS. 
    
    Grid::ProblemParameters params(GRID_SIZE, Grid::MovementType::ORTHOGONAL);
    Grid::ProblemGenerator gen;
    Grid::PathFinder planner;
    std::unique_ptr<Grid::Problem> problem = gen.generateRandomProblem(params);

    printf("Seed is: %u\n", gen.getSeed());

    planner.setProblem(problem.get());

    Grid::BreadthFirstSearch BFS;
    Grid::DepthFirstSearch DFS;

    planner.setSolver(&BFS);
    planner.solve();
    Grid::Path BFS_soln = planner.getSolution();

    planner.setSolver(&DFS);
    planner.solve();
    Grid::Path DFS_soln = planner.getSolution();

    // A legend would be nice to add
    Grid::DrawPath BFS_strat(Grid::PathColor::GREEN);
    Grid::DrawPath DFS_strat(Grid::PathColor::BLUE);

    PathRenderer BFS_rend;
    BFS_rend.setPath(&BFS_soln);
    BFS_rend.setStrategy(&BFS_strat);
    PathRenderer DFS_rend;
    DFS_rend.setPath(&DFS_soln);
    DFS_rend.setStrategy(&DFS_strat);

    SdlEngine display("Comparison Of DFS and BFS", SCREEN_SIZE, SCREEN_SIZE);
    display.addRenderable(problem->getWorld());
    display.addRenderable(problem.get());
    display.addRenderable(&BFS_rend);
    display.addRenderable(&DFS_rend);


    display.run();

    return 0;
}