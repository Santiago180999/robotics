#ifndef PATH_HPP
#define PATH_HPP

#include "Common.hpp"
#include "World.hpp"
#include "GridWorld/PathArrow.hpp"


namespace Grid
{
         
    class Path
    {
        public:
        Path() = default;
        
        Path(World* world);

        Path(const Path& other);

        ~Path();

        void addWayPoint(WayPoint point);

        WayPoint& findWayPointTo(Point point);


        World* getWorld() { return p_world; }

        void setSolutionStatus(bool isSolution);

        bool isSolutionStatus();

        std::vector<WayPoint>::iterator begin() { return m_path.begin(); }
        std::vector<WayPoint>::iterator end() { return m_path.end(); }

        private:
        std::vector<WayPoint> m_path;
        World* p_world;
        bool m_isSolution = false;



    };
}


#endif