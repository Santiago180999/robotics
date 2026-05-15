#include "Visual/PathRenderer.hpp"

void PathRenderer::setPath(Grid::Path* path)
{
    m_path = path;
}

void PathRenderer::setStrategy(Grid::IPathRenderStrategy* strategy)
{
    m_drawer = strategy;
}

void PathRenderer::render(SDL_Renderer* renderer)
{
    m_drawer->drawPath(renderer, m_path);
}