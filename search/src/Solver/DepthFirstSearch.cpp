#include "Solver/DepthFirstSearch.hpp"
#include <stack>
#include <vector>
#include <stdio.h>

namespace Grid
{
DepthFirstSearch::DepthFirstSearch(){}

DepthFirstSearch::~DepthFirstSearch(){}

void DepthFirstSearch::setProblem(Problem* problem)
{
    m_problem = problem;
    m_path = std::make_unique<Grid::Path>(m_problem->getWorld());
}

bool DepthFirstSearch::solve()
{
    std::vector<Grid::Point> visited;
    std::stack<Grid::Point> q;

    Grid::Point start = m_problem->getStartState();

    Grid::World* world = m_problem->getWorld();

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
        if (m_problem->isGoalState(x)) 
        {
            SetFinalPathBetween(start, x);
            m_path->setSolutionStatus(true);
            return true;
        }
        for (const auto& act : world->getActions())
        {
            Grid::Point xp = world->takeAction(act, x); // already checks for validity
            if (!isVisited(xp))
            {
                visited.push_back(xp);             
                m_path->addWayPoint(Grid::WayPoint(x, xp, act, Grid::EntryType::EXPLORE));
                q.push(xp);
            }
        }
    }
    m_path->setSolutionStatus(false);
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

}