#ifndef PATH_HPP
#define PATH_HPP

#include "Common.hpp"
#include "GridWorld.hpp"
#include "GridWorld/PathArrow.hpp"


namespace Grid
{
         
    class Path : public IRenderable
    {
        public: 
        Path(GridWorld* world);

        Path(const Path& other);

        ~Path();

        void addWayPoint(WayPoint point);

        WayPoint& findWayPointTo(Point point);

        void render(SDL_Renderer* renderer) override;

        virtual void drawArrow(SDL_Renderer* renderer, WayPoint& waypoint);

        void setSolutionStatus(bool isSolution);

        bool isSolutionStatus();



        protected:
        std::vector<WayPoint> m_path;
        GridWorld* p_world;
        bool m_isSolution = false;

        // convenience variable
        bool isSorted = false;

    };
}


#endif