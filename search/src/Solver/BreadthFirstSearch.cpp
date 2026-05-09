#include "Solver/BreadthFirstSearch.hpp"
#include <queue>
#include <vector>
#include <stdio.h>

BreadthFirstSearch::BreadthFirstSearch(Grid::GridWorld* world) : p_world(world) 
{
    m_path = std::make_unique<Grid::Path>(world);
}

BreadthFirstSearch::~BreadthFirstSearch()
{
    p_world = nullptr;
}

bool BreadthFirstSearch::solve(Grid::Point start)
{
    std::vector<Grid::Point> visited;
    std::queue<Grid::Point> q;

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
        Grid::Point x = q.front();
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

void BreadthFirstSearch::SetFinalPathBetween(Grid::Point startPoint, Grid::Point endPoint)
{
    if (startPoint == endPoint) return;
    Grid::WayPoint& wp = m_path->findWayPointTo(endPoint); // point is destination, wp is the waypoint whose dest is point. 
    wp.type = Grid::EntryType::FINAL;
    SetFinalPathBetween(startPoint, wp.src); // go to the source and re do. 
    return;
}

Grid::Path* BreadthFirstSearch::getSolution() 
{
    return m_path.get();
}