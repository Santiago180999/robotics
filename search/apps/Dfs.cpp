#include "Visual/SdlEngine.hpp"
#include "GridWorld/GridWorld.hpp"
#include "GridWorld/GridGenerator.hpp"
#include "Solver/DepthFirstSearch.hpp"

const size_t SCREEN_SIZE = 600;
const int GRID_SIZE = 20;

int main()
{
    SdlEngine display("Depth First Search", SCREEN_SIZE, SCREEN_SIZE);
    
    Grid::GridGenerator gen;

    std::unique_ptr<Grid::GridWorld> world = gen.GenerateWorld(GRID_SIZE, Grid::MovementType::ORTHOGONAL);
    
    bool success = false;

    DepthFirstSearch solver(world.get());
    Grid::Point st, ed;
    st = gen.GenerateRandomPoint(world.get(), GRID_SIZE);
    ed = gen.GenerateRandomPoint(world.get(), GRID_SIZE);
    printf("start: %i, %i\n", st.x, st.y);
    printf("goal: %i, %i\n", ed.x, ed.y);

    success = world->setStartCell(st); // need to create the "problem" class to replace this
    success = world->setGoalCell(ed);
    
    

    solver.solve(st);
    // make a new copy of the path for rendering
    Grid::Path* oPath = solver.getSolution();
    display.addRenderable(world.get());
    display.addRenderable(oPath);

    display.run();

    return 0;
}