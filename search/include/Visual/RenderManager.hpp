#ifndef RENDER_MANAGER_HPP
#define RENDER_MANAGER_HPP

#include "IRenderable.hpp"
#include <memory>
#include <vector>
#include <stdio.h>
class RenderManager : IRenderable
{
    public:
    RenderManager() = default;

    ~RenderManager();

    void render(SDL_Renderer* renderer) override;

    void addObject(IRenderable* obj);

    void clearObjects();

    private:
    std::vector<IRenderable*> objects;
    int numObjs=0;
};

#endif