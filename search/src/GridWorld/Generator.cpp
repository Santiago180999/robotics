#include "GridWorld/Generator.hpp"

namespace Grid
{
    Generator::Generator() 
    {
        seed = rd();
        gen = std::mt19937(seed);
        bounds = 100;
    }

    std::unique_ptr<World> Generator::GenerateWorld(size_t size, MovementType moveType)
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

        return std::make_unique<World>(grid, moveType);
    }

    Point Generator::GenerateRandomPoint(World* world)
    {
        std::uniform_int_distribution<> dist(0, bounds);
        Point x = {-1, -1}; // initially invalid point
        while (!world->isCellValid(x))
        {
            x = {dist(gen), dist(gen)};
        } 
        return x;
    }

    uint Generator::getSeed()
    {
        return seed;
    }

    void Generator::setSeed(uint sede)
    {
        seed = sede;
        gen.seed(seed); // new generator w seed
    }

}