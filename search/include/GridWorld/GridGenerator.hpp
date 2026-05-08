#ifndef GRID_GENERATOR_HPP
#define GRID_GENERATOR_HPP

#include <random>
#include "GridWorld/GridWorld.hpp"

namespace Grid
{
    class GridGenerator
    {
        public:
        GridGenerator();

        GridWorld GenerateWorld(uint size, MovementType moveType);

        Point GenerateRandomPoint(GridWorld& world, uint bounds);

        private:
        std::random_device seed;
        std::mt19937 gen;
    };
}


#endif