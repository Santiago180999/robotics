#ifndef GRID_GENERATOR_HPP
#define GRID_GENERATOR_HPP

#include <random>
#include "GridWorld/World.hpp"
#include <memory>

namespace Grid
{
    class Generator
    {
        public:
        Generator();

        std::unique_ptr<World> GenerateWorld(size_t size, MovementType moveType);

        Point GenerateRandomPoint(World* world);

        uint getSeed();

        void setSeed(uint sede);

        private:
        uint seed;
        std::random_device rd;
        std::mt19937 gen;
        uint bounds;
    };
}


#endif