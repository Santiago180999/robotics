#ifndef SDLENGINE_HPP
#define SDLENGINE_HPP

#include "SDL3/SDL.h"
#include "RenderManager.hpp"
#include <memory>

struct SDLLibrary {
    SDLLibrary() { SDL_Init(SDL_INIT_VIDEO); }
    ~SDLLibrary() { SDL_Quit(); }
};

struct SDLWindowDeleter {
    void operator()(SDL_Window* w) const { SDL_DestroyWindow(w); }
};

struct SDLRendererDeleter {
    void operator()(SDL_Renderer* r) const { SDL_DestroyRenderer(r); }
};

class SdlEngine
{
    public:
    SdlEngine(const char* title, size_t w, size_t h);

    void run();

    bool isReady() const;

    void addRenderable(IRenderable* obj);

    private:
    SDLLibrary sdlLib;
    std::unique_ptr<SDL_Window, SDLWindowDeleter> window = nullptr;
    std::unique_ptr<SDL_Renderer, SDLRendererDeleter> renderer = nullptr;
    std::unique_ptr<RenderManager> renderManager;

    bool running = false;

};


#endif