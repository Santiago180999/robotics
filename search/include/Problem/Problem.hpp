#ifndef PROBLEM_HPP
#define PROBLEM_HPP

#include "GridWorld/World.hpp"
#include "Visual/IRenderable.hpp"
#include <memory>

namespace Grid
{

class Problem : public IRenderable
{
    public:
    Problem() = default;

    ~Problem() = default;

    // return world pointer
    Grid::World* getWorld();

    Grid::Point getStartState();

    Grid::Point getGoalState();

    void setWorld(std::unique_ptr<Grid::World> world);

    void setStartState(Grid::Point state);

    void setGoalState(Grid::Point state);

    // isGoalState fn
    bool isGoalState(Grid::Point state);

    void render(SDL_Renderer* renderer) override;

    private:
    std::unique_ptr<Grid::World> m_world;
    Grid::Point m_start;
    Grid::Point m_goal;


};
}

#endif  