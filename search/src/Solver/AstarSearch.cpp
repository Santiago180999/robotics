#include "Solver/AstarSearch.hpp"
#include <queue>
#include <vector>
#include <stdio.h>

namespace Grid
{
AstarSearch::AstarSearch(){}

AstarSearch::~AstarSearch(){}

void AstarSearch::setProblem(Problem* problem)
{
    m_problem = problem;
    m_path = std::make_unique<Grid::Path>(m_problem->getWorld());
}

bool AstarSearch::solve()
{

    std::vector<std::unique_ptr<Point>> visited;

    Grid::World* world = m_problem->getWorld();

    auto isVisited = [&visited](Grid::Point pt) -> Point* {
        for (auto& vis : visited)
        {
            if (vis->wp.x == pt.x && vis->wp.y == pt.y)
            {
                return vis.get();
            }
        }
        return nullptr;
    };
    auto cmp = [](Point* l, Point* r) -> bool {
        return l->c2c + l->c2g > r->c2c + r->c2g;
    };

    std::priority_queue<Point*, std::vector<Point*>, decltype(cmp)> q(cmp);
    visited.push_back(std::unique_ptr<Point>(new Point{m_problem->getStartState(), 0})); // who owns it and who doesnt?
    Point* start = visited.back().get();
    q.push(start); // get the last element added, meaning the only one in the vector
    while (!q.empty())
    {
        Point* x = q.top();
        q.pop();
        if (m_problem->isGoalState(x->wp)) 
        {
            SetFinalPathBetween(start->wp, x->wp);
            m_path->setSolutionStatus(true);
            return true;
        }
        for (const auto& act : world->getActions())
        {
            Grid::Point xp = world->takeAction(act, x->wp); // already checks for validity
            int c2c = x->c2c + m_problem->getCost(x->wp, act); // get new cost to come
            int c2g = m_problem->getHeuristic(x->wp); // get new cost to go
            Point* dp = isVisited(xp);
            if (!dp)
            {
                visited.push_back(std::unique_ptr<Point>(new Point{xp, c2c, c2g}));             
                m_path->addWayPoint(Grid::WayPoint(x->wp, xp, act, Grid::EntryType::EXPLORE));
                q.push(visited.back().get()); // get the latest added
            }
            else // is visited, compare c2c+c2g
            {
                if (dp->c2c + dp->c2g > c2c+c2g)
                {
                    // if the known cost is higher than new cost, update
                    dp->wp = xp;
                    dp->c2c = c2c;
                    dp->c2g = c2g;
                    // update the path too
                    Grid::WayPoint& pp = m_path->findWayPointTo(xp);
                    pp.src = x->wp;
                }
            }
        }
    }
    m_path->setSolutionStatus(false);
    return false;
}

void AstarSearch::SetFinalPathBetween(Grid::Point startPoint, Grid::Point endPoint)
{
    if (startPoint == endPoint) return;
    Grid::WayPoint& wp = m_path->findWayPointTo(endPoint); // point is destination, wp is the waypoint whose dest is point. 
    wp.type = Grid::EntryType::FINAL;
    SetFinalPathBetween(startPoint, wp.src); // go to the source and re do. 
    return;
}

Grid::Path* AstarSearch::getSolution() 
{
    return m_path.get();
}

}