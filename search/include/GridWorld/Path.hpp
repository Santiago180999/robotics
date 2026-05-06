#ifndef PATH_HPP
#define PATH_HPP

#include "Common.hpp"
#

namespace Grid
{
    enum EntryType 
    {
        FINAL, 
        EXPLORE
    };

    struct WayPoint
    {
        Point src, dest;
        ActionType action; 
        EntryType type;

        WayPoint() 
        {
            src = {0,0}; 
            dest = {0,0};
            action = INPLACE;
            type = FINAL;
        }

        WayPoint(Point source, Point desti, ActionType act, EntryType tipe) : src(source), dest(desti), action(act), type(tipe) {}
    };

    class Path : IVisual
    {
        public: 
        Path() = default;

        void addWayPoint(WayPoint point);

        void render(SDL_Renderer* renderer) override;

        private:
        std::vector<WayPoint> m_path;
        // TODO: need to come back to define the ops to do on a path...

    };
}


#endif