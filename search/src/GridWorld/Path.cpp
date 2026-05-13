#include "GridWorld/Path.hpp"
#include <algorithm>


namespace Grid
{

    Path::Path(Grid::GridWorld* world) : p_world(world) {}

    Path::Path(const Path& other)
    {
        m_path = other.m_path;
        p_world = other.p_world;
    }

    Path::~Path()
    {
        p_world = nullptr;
        m_path.clear();
    }
    
    void Path::drawArrow(SDL_Renderer* renderer, WayPoint& waypoint)
    {

        int width;
        int height;
        SDL_GetCurrentRenderOutputSize(renderer, &width, &height);
        size_t gridSize = p_world->getGrid().size();
        float cellSize = (float)width / gridSize;
        SDL_FColor color;

        switch (waypoint.type)
        {
        case EntryType::FINAL:
            color = PathColor::FINAL; 
            break;
        case EntryType::EXPLORE:
            color =  PathColor::EXPLORE;
            break;
        default: 
            color =  PathColor::DEFAULT;
            break;
        }

        PathArrow arrow(waypoint, color, cellSize);
        SDL_RenderGeometry(renderer, NULL, arrow.getVertices(), arrow.getVertexCount(), arrow.getIndices(), arrow.getIndexCount());
        const char* x = SDL_GetError();
    }

    void Path::addWayPoint(WayPoint point)
    {
        m_path.push_back(point);
    }

    void Path::render(SDL_Renderer* renderer)
    {
        // sort the path according to waypoint type so that the final path shows above the others
        std::sort(m_path.begin(), m_path.end(), 
            [](const WayPoint &a, const WayPoint &b){
                return a.type > b.type;
            }); // this could be non-performant if called at every render iteration...

        for (auto& wp : m_path)
        {
            drawArrow(renderer, wp);
        }
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

}