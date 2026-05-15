#include "GridWorld/ColoredPath.hpp"

namespace Grid
{
    ColoredPath::ColoredPath(World* world, SDL_FColor color) : Path(world)
    {
        setColor(color);
    }

    ColoredPath::ColoredPath(ColoredPath& other) : Path(other)
    {
        setColor(other.color);
    }


    ColoredPath::ColoredPath(const Path& other, SDL_FColor color) : Path(other)
    {
        setColor(color);
    }

    void ColoredPath::setColor(SDL_FColor color)
    {
        this->color = color;
    }

    ColoredPath ColoredPath::ColorPathWith(const Path& source, SDL_FColor color)
    {
        return ColoredPath(source, color);
    }
    
    void ColoredPath::render(SDL_Renderer* renderer)
    {
        for (auto& wp : m_path)
        {
            drawArrow(renderer, wp);
        }
    }

    void ColoredPath::drawArrow(SDL_Renderer* renderer, WayPoint& waypoint)
    {
        int width;
        int height;
        SDL_GetCurrentRenderOutputSize(renderer, &width, &height);
        size_t gridSize = p_world->getGrid().size();
        float cellSize = (float)width / gridSize;

        if (waypoint.type == EntryType::FINAL)
        {
            PathArrow arrow(waypoint, color, cellSize);
            SDL_RenderGeometry(renderer, NULL, arrow.getVertices(), arrow.getVertexCount(), arrow.getIndices(), arrow.getIndexCount());
            const char* x = SDL_GetError();
        }
    }

}