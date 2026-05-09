#ifndef IRENDERABLE_HPP
#define IRENDERABLE_HPP

#include <SDL3/SDL.h>

class IRenderable
{
    public:

    virtual ~IRenderable() = default;

    virtual void render(SDL_Renderer* renderer) = 0;
};

#endif