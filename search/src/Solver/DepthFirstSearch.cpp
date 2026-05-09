#include "Solver/DepthFirstSearch.hpp"
#include <stack>
#include <vector>
#include <stdio.h>

DepthFirstSearch::DepthFirstSearch(Grid::GridWorld* world) : p_world(world) 
{
    m_path = std::make_unique<Grid::Path>(world);
}

DepthFirstSearch::~DepthFirstSearch()
{
    p_world = nullptr;
}

bool DepthFirstSearch::solve(Grid::Point start)
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
        if (p_world->isCellGoal(x)) 
        {
            SetFinalPathBetween(start, x);
            return true;
        }
        for (const auto& act : p_world->getActions())
        {
            Grid::Point xp = p_world->takeAction(act, x); // already checks for validity
            if (!isVisited(xp))
            {
                visited.push_back(xp);             
                m_path->addWayPoint(Grid::WayPoint(x, xp, act, Grid::EntryType::EXPLORE));
                q.push(xp);
            }
        }
    }
    return false;

}

void DepthFirstSearch::SetFinalPathBetween(Grid::Point startPoint, Grid::Point endPoint)
{
    if (startPoint == endPoint) return;
    Grid::WayPoint& wp = m_path->findWayPointTo(endPoint); // point is destination, wp is the waypoint whose dest is point. 
    wp.type = Grid::EntryType::FINAL;
    SetFinalPathBetween(startPoint, wp.src); // go to the source and re do. 
    return;
}

Grid::Path* DepthFirstSearch::getSolution() 
{
    return m_path.get();
}