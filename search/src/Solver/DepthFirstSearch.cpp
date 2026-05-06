#include "Solver/DepthFirstSearch.hpp"
#include <stack>
#include <vector>
#include <stdio.h>

DepthFirstSearch::DepthFirstSearch() {}

bool DepthFirstSearch::solve(Grid::GridWorld& world, Grid::Point start)
{
    std::vector<Grid::Point> visited;
    std::stack<Grid::Point> q;

    auto isVisited = [&visited](Grid::Point pt) {
        for (auto& vis : visited)
        {
            if (vis.x == pt.x && vis.y == pt.y)
            {
                return true;
            }
        }
        return false;
    };

    q.push(start);
    while(!q.empty())
    {
        Grid::Point x = q.top();
        q.pop();
        if (world.isCellGoal(x)) 
        {
            return true;
        }
        for (auto& act : world.ACTIONS)
        {
            Grid::Point xp = world.takeAction(act, x);
            if (!isVisited(xp))
            {
                visited.push_back(xp);
                if (world.isCellEmpty(xp))
                {                
                    m_path.addWayPoint(Grid::WayPoint(x, xp, act, Grid::EntryType::EXPLORE));
                    q.push(xp);
                }
            }
        }
    }
    return false;

}

Grid::Path& DepthFirstSearch::getSolution() 
{
    return m_path;
}