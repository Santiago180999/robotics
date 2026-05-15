#ifndef COLORED_PATH_HPP
#define COLORED_PATH_HPP

#include "GridWorld/Path.hpp"
#include "GridWorld/PathArrow.hpp"

// TODO: redefine this class as a decorator of the path, or a strategy
namespace Grid
{
    class ColoredPath : public Path
    {
        public:

        ColoredPath(World* world, SDL_FColor color);

        ColoredPath(ColoredPath& other);

        ColoredPath(const Path& other, SDL_FColor color);

        void setColor(SDL_FColor color);

        void render(SDL_Renderer* renderer) override;

        void drawArrow(SDL_Renderer* renderer, WayPoint& waypoint) override;

        static ColoredPath ColorPathWith(const Path& source, SDL_FColor color);
    
        private:
        SDL_FColor color = PathColor::DEFAULT;
    };
}
#endif