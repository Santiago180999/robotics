#ifndef COMMON_HPP
#define COMMON_HPP

#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Visual/IRenderable.hpp"

namespace Grid
{
    class GridWorld;
    class Path;
    
    enum CellType { EMPTY, WALL, AGENT, START, GOAL };

    class Grid2D
    {
        public:
        Grid2D(int size) : m_size(size), grid(size, std::vector<CellType>(size, EMPTY)) {}

        // 1. Non-const version (allows modification: grid[y][x] = value)
        std::vector<CellType>& operator[](size_t index) {
            return grid[index];
        }

        // 2. Const version (for read-only access: T val = grid[y][x])
        const std::vector<CellType>& operator[](size_t index) const {
            return grid[index];
        }

        size_t size() const { return m_size; }

        private:
        size_t m_size; // assume square
        std::vector<std::vector<CellType>> grid;
    };

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