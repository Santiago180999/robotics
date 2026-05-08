#include "GridWorld/GridGenerator.hpp"

namespace Grid
{
    GridGenerator::GridGenerator() : seed(), gen(seed()) {}

    GridWorld GridGenerator::GenerateWorld(uint size, MovementType moveType)
    {
        std::bernoulli_distribution dist(0.35);
        Grid2D grid(size, std::vector<CellType>(size, EMPTY));
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

        return GridWorld(grid, moveType);
    }

    Point GridGenerator::GenerateRandomPoint(GridWorld& world, uint bounds)
    {
        std::uniform_int_distribution<> dist(0, bounds);
        Point x = {-1, -1}; // initially invalid point
        while (!world.isCellValid(x))
        {
            x = {dist(gen), dist(gen)};
        } 
        return x;
    }
}