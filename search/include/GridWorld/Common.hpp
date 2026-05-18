#ifndef COMMON_HPP
#define COMMON_HPP

#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Visual/IRenderable.hpp"

namespace Grid
{
    class World;
    class Path;

    enum EntryType 
    {
        FINAL, 
        EXPLORE
    };

    namespace PathColor
    {
        const SDL_FColor DEFAULT = {1, 1, 1, 1};
        const SDL_FColor EXPLORE = {0.95, 0.89, 0.57, 1.0};
        const SDL_FColor FINAL = {0.2, 0.2, 0.9, 1.0};
        const SDL_FColor GREEN = {0.212, 0.859, 0.027, 1.0};
        const SDL_FColor BLUE = {0.129, 0.157, 0.929};
        const SDL_FColor RED = {0.949, 0.169, 0.067};
        const SDL_FColor PINK = {0.949, 0.067, 0.945};
        const SDL_FColor PURPLE = {0.675, 0.067, 0.949};
    }
    
    enum CellType { EMPTY, WALL, AGENT };

    class Grid2D // could redefine this later to add a different value to each cell to calculate the cost to move
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

    struct WayPoint
    {
        Point src, dest;
        ActionType action; 
        EntryType type;

        WayPoint() 
        {
            src = {0,0}; 
            dest = {0,0};
            action = INPLACE;
            type = FINAL;
        }

        WayPoint(Point source, Point desti, ActionType act, EntryType tipe) : src(source), dest(desti), action(act), type(tipe) {}
    };
}

#endif