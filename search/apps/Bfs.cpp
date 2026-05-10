#include "Visual/SdlEngine.hpp"
#include "Solver/BreadthFirstSearch.hpp"
#include "Problem/ProblemGenerator.hpp"

const size_t SCREEN_SIZE = 600;
const int GRID_SIZE = 20;

int main(int argc, char* argv[])
{
    SdlEngine display("Breadth First Search", SCREEN_SIZE, SCREEN_SIZE);
    
    ProblemGenerator problem;

    problem.generateWorld(GRID_SIZE, Grid::MovementType::ORTHOGONAL);
    
    problem.setStartState();
    problem.setGoalState();
    
    BreadthFirstSearch solver(problem);
    
    solver.solve();

    display.addRenderable(problem.getWorld());
    display.addRenderable(&problem);
    display.addRenderable(solver.getSolution()); // how can i superimpose various paths?
    display.run();

    return 0;
}