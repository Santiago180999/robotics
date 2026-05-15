#ifndef PATHRENDERSTRATEGY_HPP
#define PATHRENDERSTRATEGY_HPP

#include "Common.hpp"
#include "PathArrow.hpp"
#include "Path.hpp"



namespace Grid
{
class IPathRenderStrategy
{
    public:
    ~IPathRenderStrategy() = default;

    virtual void drawPath(SDL_Renderer* renderer, Path* path) = 0;

    virtual void drawArrow(SDL_Renderer* renderer, WayPoint& waypoint, float cellSize) = 0;
};

class DrawPath : public IPathRenderStrategy
{
    public:
    DrawPath(SDL_FColor pathColor);

    void drawPath(SDL_Renderer* renderer, Grid::Path* path) override;

    void drawArrow(SDL_Renderer* renderer, WayPoint& waypoint, float cellSize) override;

    private:
    SDL_FColor m_color = PathColor::FINAL;

};

class ShowExplorationDecorator : public IPathRenderStrategy
{
    public:
    ShowExplorationDecorator(SDL_FColor exploreColor, DrawPath* base);

    void drawPath(SDL_Renderer* renderer, Grid::Path* path) override;

    void drawArrow(SDL_Renderer* renderer, WayPoint& waypoint, float cellSize) override;
    
    private:
    DrawPath* m_base;
    SDL_FColor m_color = PathColor::EXPLORE;
};

}

#endif