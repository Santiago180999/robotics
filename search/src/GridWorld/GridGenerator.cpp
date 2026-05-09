#include "GridWorld/GridGenerator.hpp"

namespace Grid
{
    GridGenerator::GridGenerator() : seed(), gen(seed()) {}

    std::unique_ptr<GridWorld> GridGenerator::GenerateWorld(size_t size, MovementType moveType)
    {
        std::bernoulli_distribution dist(0.35);
        Grid2D grid(size);
        // loop over the grid
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (dist(gen))
                {
                    grid[j][i] = WALL;
                }
            }
        }

        return std::make_unique<GridWorld>(grid, moveType);
    }

    Point GridGenerator::GenerateRandomPoint(GridWorld* world, uint bounds)
    {
        std::uniform_int_distribution<> dist(0, bounds);
        Point x = {-1, -1}; // initially invalid point
        while (!world->isCellValid(x))
        {
            x = {dist(gen), dist(gen)};
        } 
        return x;
    }
}