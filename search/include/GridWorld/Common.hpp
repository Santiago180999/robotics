#ifndef COMMON_HPP
#define COMMON_HPP

#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Visual/IVisual.hpp"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const int GRID_SIZE = 20;
const float CELL_SIZE = (float)SCREEN_WIDTH / GRID_SIZE;

namespace Grid
{
    enum CellType { EMPTY, WALL, AGENT, START, GOAL };

    using Grid2D = std::vector<std::vector<CellType>>;

    struct Point 
    { 
        int x, y;
        
        bool operator== (const Point& rhs) const
        {
            return ((x == rhs.x) && (y == rhs.y));
        }
    };

    enum ActionType
    {
        INPLACE,
        UP,
        DOWN, 
        LEFT, 
        RIGHT, 
        NORTHEAST,
        NORTHWEST,
        SOUTHEAST,
        SOUTHWEST
    };
}

#endif