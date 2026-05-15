#include "GridWorld/PathRenderStrategy.hpp"

namespace Grid 
{

DrawPath::DrawPath(SDL_FColor pathColor) : m_color(pathColor){}

void DrawPath::drawPath(SDL_Renderer* renderer, Grid::Path* path)
{
    int width;
    int height;
    SDL_GetCurrentRenderOutputSize(renderer, &width, &height);
    size_t gridSize = path->getWorld()->getGrid().size();
    float cellSize = (float)width / gridSize;

    if (path->isSolutionStatus())
    {
        for (auto& wp : *path)
        {
            if (wp.type == EntryType::FINAL)
            {
                drawArrow(renderer, wp, cellSize);
            }
        }
    }
    // there could be a case where if no solutoi nwas found, automatically set the color of the xplore, but id need to accoutn for the various paths being displayed to change the color of the explore arrow for each path
}

void DrawPath::drawArrow(SDL_Renderer* renderer, WayPoint& waypoint, float cellSize)
{
    PathArrow arrow(waypoint, m_color, cellSize);
    SDL_RenderGeometry(renderer, NULL, arrow.getVertices(), arrow.getVertexCount(), arrow.getIndices(), arrow.getIndexCount());
    const char* x = SDL_GetError();
}

ShowExplorationDecorator::ShowExplorationDecorator(SDL_FColor exploreColor, DrawPath* base) : m_color(exploreColor), m_base(base) {}

void ShowExplorationDecorator::drawPath(SDL_Renderer* renderer, Grid::Path* path)
{
    int width;
    int height;
    SDL_GetCurrentRenderOutputSize(renderer, &width, &height);
    size_t gridSize = path->getWorld()->getGrid().size();
    float cellSize = (float)width / gridSize;

    for (auto& wp : *path)
    {
        if (wp.type == EntryType::EXPLORE)
        {
            drawArrow(renderer, wp, cellSize);
        }
    } 
    m_base->drawPath(renderer, path); // draw final path
}

void ShowExplorationDecorator::drawArrow(SDL_Renderer* renderer, WayPoint& waypoint, float cellSize)
{
    PathArrow arrow(waypoint, m_color, cellSize);
    SDL_RenderGeometry(renderer, NULL, arrow.getVertices(), arrow.getVertexCount(), arrow.getIndices(), arrow.getIndexCount());
    const char* x = SDL_GetError();
}


}