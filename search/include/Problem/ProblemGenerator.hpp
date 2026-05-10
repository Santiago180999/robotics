#ifndef PROBLEM_GEN_HPP
#define PROBLEM_GEN_HPP

#include "GridWorld/GridWorld.hpp"
#include "GridWorld/GridGenerator.hpp"
#include "Visual/IRenderable.hpp"

class ProblemGenerator : public IRenderable
{
    public:
    ProblemGenerator() = default;

    ~ProblemGenerator() = default;

    // generate world
    void generateWorld(size_t size, Grid::MovementType moveType);

    // return world pointer
    Grid::GridWorld* getWorld();

    // set start state
    void setStartState(); // start cell could be a renderable instead of a cell in the grid world
    // set goal state
    void setGoalState();

    Grid::Point getStartState();

    Grid::Point getGoalState();

    // isGoalState fn
    bool isGoalState(Grid::Point loc);

    void render(SDL_Renderer* renderer) override;

    private:
    std::unique_ptr<Grid::GridWorld> m_world;
    Grid::GridGenerator m_generator;
    Grid::Point m_start, m_goal;


};

#endif  