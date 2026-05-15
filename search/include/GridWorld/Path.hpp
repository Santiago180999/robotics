#ifndef PATH_HPP
#define PATH_HPP

#include "Common.hpp"
#include "World.hpp"
#include "GridWorld/PathArrow.hpp"


namespace Grid
{
         
    class Path : public IRenderable
    {
        public:
        Path() = default;
        
        Path(World* world);

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
        World* p_world;
        bool m_isSolution = false;

        /* TODO:
            maybe the path can take a strategy as a parameter to draw the arrow, 
            the strategies rn are:
                draw explore and final in a path, should provide the ability to choose different colors
                draw only final path
        */
        // convenience variable
        bool isSorted = false;


    };
}


#endif