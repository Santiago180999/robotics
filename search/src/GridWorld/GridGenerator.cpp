#include "GridWorld/GridGenerator.hpp"

namespace Grid
{
    GridGenerator::GridGenerator() : seed(), gen(seed()) {}

    GridWorld GridGenerator::GenerateWorld(uint size)
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

        return GridWorld(grid);
    }
}