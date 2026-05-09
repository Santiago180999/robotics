#include "Visual/SdlEngine.hpp"
#include "GridWorld/GridWorld.hpp"
#include "GridWorld/GridGenerator.hpp"
#include "Solver/BreadthFirstSearch.hpp"

const size_t SCREEN_SIZE = 600;
const int GRID_SIZE = 20;

int main(int argc, char* argv[])
{
    SdlEngine display("Breadth First Search", SCREEN_SIZE, SCREEN_SIZE);
    
    Grid::GridGenerator gen;

    std::unique_ptr<Grid::GridWorld> world = gen.GenerateWorld(GRID_SIZE, Grid::MovementType::ORTHOGONAL);
    
    bool success = false;

    BreadthFirstSearch solver(world.get());
    Grid::Point st, ed;
    st = gen.GenerateRandomPoint(world.get(), GRID_SIZE);
    ed = gen.GenerateRandomPoint(world.get(), GRID_SIZE);
    printf("start: %i, %i\n", st.x, st.y);
    printf("goal: %i, %i\n", ed.x, ed.y);

    success = world->setStartCell(st); // need to create the "problem" class to replace this
    success = world->setGoalCell(ed);
    
    solver.solve(st);
    

    display.addRenderable(world.get());
    display.addRenderable(solver.getSolution()); // how can i superimpose various paths?
    display.run();

    return 0;
}