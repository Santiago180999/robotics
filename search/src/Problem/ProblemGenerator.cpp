#include "Problem/ProblemGenerator.hpp"

void ProblemGenerator::generateWorld(size_t size, Grid::MovementType moveType)
{
    m_world = m_generator.GenerateWorld(size, moveType);
}

Grid::GridWorld* ProblemGenerator::getWorld()
{
    return m_world.get();
}

void ProblemGenerator::setStartState()
{
    m_start = m_generator.GenerateRandomPoint(m_world.get());

}

void ProblemGenerator::setGoalState()
{
    m_goal = m_generator.GenerateRandomPoint(m_world.get());
}

Grid::Point ProblemGenerator::getStartState()
{
    return m_start;
}

Grid::Point ProblemGenerator::getGoalState()
{
    return m_goal;
}

bool ProblemGenerator::isGoalState(Grid::Point loc)
{
    if (loc == m_goal)
    {
        return true;
    }
    else return false;
}

void ProblemGenerator::render(SDL_Renderer* renderer)
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