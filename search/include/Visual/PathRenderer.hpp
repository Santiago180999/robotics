// id like to implement the path renderer as a strategy, where there are different strategies to render the path on the grid. 

#ifndef PATHRENDERER_HPP
#define PATHRENDERER_HPP

#include "IRenderable.hpp"
#include "GridWorld/PathRenderStrategy.hpp"
#include "GridWorld/Path.hpp"
#include "GridWorld/PathArrow.hpp"

class PathRenderer : public IRenderable
{
    public:
    PathRenderer() = default;

    void setPath(Grid::Path* path);

    void setStrategy(Grid::IPathRenderStrategy* strategy);

    void render(SDL_Renderer* renderer) override;

    private:
    Grid::Path* m_path;
    Grid::IPathRenderStrategy* m_drawer;

};


#endif 