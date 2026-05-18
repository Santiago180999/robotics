#include "Problem/Problem.hpp"

namespace Grid
{

Grid::World* Problem::getWorld()
{
    return m_world.get();
}

Grid::Point Problem::getStartState()
{
    return m_start;
}

Grid::Point Problem::getGoalState()
{
    return m_goal;
}

void Problem::setStartState(Grid::Point state)
{
    m_start = state;
}

void Problem::setGoalState(Grid::Point state)
{
    m_goal = state;
}

void Problem::setWorld(std::unique_ptr<Grid::World> world)
{
    m_world = std::move(world);
}


bool Problem::isGoalState(Grid::Point state)
{
    if (state == m_goal)
    {
        return true;
    }
    else return false;
}

int Problem::getCost(Grid::Point state, ActionType action)
{
    // fill in with arbitrary cost function
    return 1;
}

int Problem::getHeuristic(Grid::Point state)
{
    // using L1 norm
    return std::abs(m_goal.x - state.x) + std::abs(m_goal.y - state.y); // |x'-x| + |y'-y|
}


void Problem::render(SDL_Renderer* renderer)
{
    int width;
    int height;
    SDL_GetCurrentRenderOutputSize(renderer, &width, &height);
    const char* x = SDL_GetError();
    size_t gridSize = m_world->getGrid().size();
    float CELL_SIZE = (float)width / gridSize;
    float circleDiameter = CELL_SIZE * 0.5;

    float xs = m_start.x * CELL_SIZE + CELL_SIZE/2;
    float ys = m_start.y * CELL_SIZE + CELL_SIZE/2;
    float xg = m_goal.x * CELL_SIZE + CELL_SIZE/2;
    float yg = m_goal.y * CELL_SIZE + CELL_SIZE/2;

    SDL_Vertex stvertices[3];
    SDL_Vertex glvertices[3];

    SDL_FColor stColor = {45/255.0, 245/255.0, 39/255.0, 255/255.0};
    SDL_FColor glColor ={245/255.0, 39/255.0, 39/255.0, 255/255.0};

    //START:
    // Define the three corners relative to a center point (x, y)
    // Top Vertex
    stvertices[0].position = { xs, ys - circleDiameter };
    stvertices[0].color = stColor; 

    // Bottom Left (Green)
    stvertices[1].position = { xs - circleDiameter, ys + circleDiameter };
    stvertices[1].color = stColor; 

    // Bottom Right (Blue)
    stvertices[2].position = { xs + circleDiameter, ys + circleDiameter };
    stvertices[2].color = stColor; 

    //GOAL:
    // Define the three corners relative to a center point (x, y)
    // Top Vertex
    glvertices[0].position = { xg, yg - circleDiameter };
    glvertices[0].color = glColor; 

    // Bottom Left (Green)
    glvertices[1].position = { xg - circleDiameter, yg + circleDiameter };
    glvertices[1].color = glColor; 

    // Bottom Right (Blue)
    glvertices[2].position = { xg + circleDiameter, yg + circleDiameter };
    glvertices[2].color = glColor; 

    SDL_RenderGeometry(renderer, NULL, stvertices, 3, NULL, 0);
    SDL_RenderGeometry(renderer, NULL, glvertices, 3, NULL, 0);

}

}