#include "GridWorld/Path.hpp"
#include <algorithm>


namespace Grid
{

    Path::Path(Grid::World* world) : p_world(world) {}

    Path::Path(const Path& other)
    {
        m_path = other.m_path;
        p_world = other.p_world;
        m_isSolution = other.m_isSolution;
    }

    Path::~Path()
    {
        p_world = nullptr;
        m_path.clear();
    }
    
        void Path::addWayPoint(WayPoint point)
    {
        m_path.push_back(point);
    }

    WayPoint& Path::findWayPointTo(Point point)
    {
        auto cond = [&](WayPoint wp){
            if (wp.dest == point)
            {
                return true;
            }
            else return false;
        };

        auto it = std::find_if(m_path.begin(), m_path.end(), cond);

        return *it;
    }

    void Path::setSolutionStatus(bool isSolution)
    {
        m_isSolution = isSolution;
    }

    bool Path::isSolutionStatus() 
    {
        return m_isSolution;
    }

}