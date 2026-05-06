#include "GridWorld/GridWorld.hpp"
#include "GridWorld/GridGenerator.hpp"
#include "Solver/DepthFirstSearch.hpp"
#include <SDL3/SDL.h>

int main(int argc, char* argv[]) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL3 Grid World", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    Grid::GridGenerator gen;
    Grid::GridWorld world = gen.GenerateWorld(uint(20));
    Grid::Path path;        
    Grid::Point st = world.setStartCell(Grid::Point{4,6});
    world.setGoalCell(Grid::Point{11,10});

    DepthFirstSearch solver;
    if (solver.solve(world, st))
    {
        printf("Success!\n");
    }
    else
    {
        printf("failure\n");
    }



    bool running = true;
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) running = false;
            world.handleInput(e);
        }

        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_RenderClear(renderer);
        
        world.render(renderer);
        solver.getSolution().render(renderer);
        
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}