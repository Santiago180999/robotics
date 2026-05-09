#ifndef GRID_GENERATOR_HPP
#define GRID_GENERATOR_HPP

#include <random>
#include "GridWorld/GridWorld.hpp"
#include <memory>

namespace Grid
{
    class GridGenerator
    {
        public:
        GridGenerator();

        std::unique_ptr<GridWorld> GenerateWorld(size_t size, MovementType moveType);

        Point GenerateRandomPoint(GridWorld* world, uint bounds);

        private:
        std::random_device seed;
        std::mt19937 gen;
    };
}


#endif