#include "Visual/RenderManager.hpp"

RenderManager::~RenderManager()
{

    clearObjects();
}

void RenderManager::render(SDL_Renderer* renderer)
{
    for (int i = 0; i < numObjs; i++)
    {
        objects[i]->render(renderer);
    }
}

void RenderManager::addObject(IRenderable* obj)
{
    objects.push_back(obj);
    numObjs++;
}

void RenderManager::clearObjects()
{
    objects.clear();
    numObjs = 0;
}
