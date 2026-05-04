#ifndef GRID_WORLD_HPP
#define GRID_WORLD_HPP

#include <vector>

// here id like to define a way to generate a grid world.
// given an arbitrary grid size, randomly initialize a transition graph
// random based on a probability when generating it.
// deals w edges. 

// at some point id like it to be an extension of a base class, that includes other worlds

class GridWorld
{
    public:
    GridWorld(); // given a grid size

    


    private:
    std::vector<int> grid;

}


#endif