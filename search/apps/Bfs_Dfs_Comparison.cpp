#include "Visual/SdlEngine.hpp"
#include "Solver/BreadthFirstSearch.hpp"
#include "Solver/DepthFirstSearch.hpp"
#include "Problem/ProblemGenerator.hpp"
#include "GridWorld/ColoredPath.hpp"

const size_t SCREEN_SIZE = 600;
const int GRID_SIZE = 30;

int main(int argc, char* argv[])
{
    SdlEngine display("Comparison Of DFS and BFS", SCREEN_SIZE, SCREEN_SIZE);
    
    ProblemGenerator problem;

    // TODO: would be cool to get a repeatable world. i think should be possible knowing the seed
    problem.generateWorld(GRID_SIZE, Grid::MovementType::ORTHOGONAL);
    
    problem.setStartState();
    problem.setGoalState();
    
    BreadthFirstSearch BFS(problem);
    DepthFirstSearch DFS(problem);
    
    BFS.solve();
    DFS.solve();

    display.addRenderable(problem.getWorld());
    display.addRenderable(&problem);

    // A legend would be nice to add
    Grid::ColoredPath BFS_soln = Grid::ColoredPath::ColorPathWith(*BFS.getSolution(), Grid::PathColor::GREEN);
    Grid::ColoredPath DFS_soln = Grid::ColoredPath::ColorPathWith(*DFS.getSolution(), Grid::PathColor::BLUE);

    display.addRenderable(&BFS_soln);
    display.addRenderable(&DFS_soln);

    display.run();

    return 0;
}