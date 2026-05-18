#include "Visual/SdlEngine.hpp"
#include "Solver/BreadthFirstSearch.hpp"
#include "Solver/DepthFirstSearch.hpp"
#include "Solver/DijkstrasSearch.hpp"
#include "Solver/AstarSearch.hpp"
#include "Solver/PathFinder.hpp"
#include "Problem/ProblemGenerator.hpp"
#include "Visual/PathRenderer.hpp"
#include "GridWorld/PathRenderStrategy.hpp"

const size_t SCREEN_SIZE = 600;
const int GRID_SIZE = 30;

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
    Grid::DijkstrasSearch DES;
    Grid::AstarSearch AST;

    planner.setSolver(&BFS);
    planner.solve();
    Grid::Path BFS_soln = planner.getSolution();

    planner.setSolver(&DFS);
    planner.solve();
    Grid::Path DFS_soln = planner.getSolution();

    planner.setSolver(&DES);
    planner.solve();
    Grid::Path DES_soln = planner.getSolution();

    planner.setSolver(&AST);
    planner.solve();
    Grid::Path AST_soln = planner.getSolution();

    // A legend would be nice to add
    Grid::DrawPath BFS_strat(Grid::PathColor::GREEN);
    Grid::DrawPath DFS_strat(Grid::PathColor::BLUE);
    Grid::DrawPath DES_strat(Grid::PathColor::PURPLE);
    Grid::DrawPath AST_strat(Grid::PathColor::RED);

    PathRenderer BFS_rend;
    BFS_rend.setPath(&BFS_soln);
    BFS_rend.setStrategy(&BFS_strat);
    PathRenderer DFS_rend;
    DFS_rend.setPath(&DFS_soln);
    DFS_rend.setStrategy(&DFS_strat);
    PathRenderer DES_rend;
    DES_rend.setPath(&DES_soln);
    DES_rend.setStrategy(&DES_strat);
    PathRenderer AST_rend;
    AST_rend.setPath(&AST_soln);
    AST_rend.setStrategy(&AST_strat);

    SdlEngine display("Comparison of Search Algorithms", SCREEN_SIZE, SCREEN_SIZE);
    display.addRenderable(problem->getWorld());
    display.addRenderable(problem.get());
    display.addRenderable(&BFS_rend);
    display.addRenderable(&DFS_rend);
    display.addRenderable(&DES_rend);
    display.addRenderable(&AST_rend);


    display.run();

    return 0;
}