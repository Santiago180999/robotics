#include "Visual/SdlEngine.hpp"

SdlEngine::SdlEngine(const char* title, size_t w, size_t h)
{
    SDL_PropertiesID props = SDL_CreateProperties();
    SDL_SetStringProperty(props, SDL_PROP_WINDOW_CREATE_TITLE_STRING, title);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_WIDTH_NUMBER, w);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_HEIGHT_NUMBER, h);
    SDL_SetBooleanProperty(props, SDL_PROP_WINDOW_CREATE_HIDDEN_BOOLEAN, true);
    renderManager = std::make_unique<RenderManager>();
    window.reset(SDL_CreateWindowWithProperties(props));
    renderer.reset(SDL_CreateRenderer(window.get(), NULL));
    running = true;
    SDL_ShowWindow(window.get());
}

void SdlEngine::run() 
{
    SDL_Event e;
    while (running) {
        // 1. Process Events
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                running = false;
            }
            // Here you could pass events to your grid or objects
        }

        // 2. Clear Screen
        SDL_SetRenderDrawColor(renderer.get(), 15, 15, 15, 255); // Dark background
        SDL_RenderClear(renderer.get());

        // 3. Render all registered objects
        renderManager->render(renderer.get());

        // 4. Present
        SDL_RenderPresent(renderer.get());
    }
    return;
}

bool SdlEngine::isReady() const 
{ 
    return running; 
}

void SdlEngine::addRenderable(IRenderable* obj)
{
    if (obj)
    {
        renderManager->addObject(obj);
    }  
}
    
