#ifndef IVISUAL_HPP
#define IVISUAL_HPP

#include <SDL3/SDL.h>

class IVisual
{
    public:
    virtual void render(SDL_Renderer* renderer) = 0;
};

#endif