#include "GridWorld/Path.hpp"
#include <algorithm>

const int ARROW_WIDTH = 3;
const float EPS = 0.5;

namespace Grid
{
    Path::Path(Grid::GridWorld* world) : p_world(world) {}

    Path::Path(Path& other)
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
        const char* x = SDL_GetError();
        size_t gridSize = p_world->getGrid().size();
        float CELL_SIZE = (float)width / gridSize;
        float arrowHeadSize = 8;
        float xs = waypoint.src.x * CELL_SIZE + CELL_SIZE/2;
        float ys = waypoint.src.y * CELL_SIZE + CELL_SIZE/2;
        float xd = waypoint.dest.x * CELL_SIZE + CELL_SIZE/2;
        float yd = waypoint.dest.y * CELL_SIZE + CELL_SIZE/2;

        SDL_FRect rect;
            
        // Define the three corners relative to a center point (x, y)
        SDL_Vertex vertices[3];
        float alpha = 0;
        SDL_FColor color;

        switch (waypoint.type)
        {
        case EntryType::FINAL:
            alpha = 1;
            color =  { 0.2, 0.2, 0.9, alpha }; 
            break;
        case EntryType::EXPLORE:
            alpha = 1;
            color =  { 0.95, 0.89, 0.57, alpha }; 
            break;
        default: 
            alpha = 1;
            color =  { 1, 1, 1, alpha }; 
            break;
        }
        
        SDL_SetRenderDrawColor(renderer, color.r*256, color.g*256, color.b*256, color.a*256);
        switch (waypoint.action)
        {
        case ActionType::UP:
            rect = { xd-ARROW_WIDTH/2, yd, ARROW_WIDTH, CELL_SIZE};
            // Define the three corners relative to a center point (x, y)
            // Top Vertex
            vertices[0].position = { xd, yd - arrowHeadSize };
            vertices[0].color = color; 

            // Bottom Left (Green)
            vertices[1].position = { xd - arrowHeadSize, yd + arrowHeadSize };
            vertices[1].color = color; 

            // Bottom Right (Blue)
            vertices[2].position = { xd + arrowHeadSize, yd + arrowHeadSize };
            vertices[2].color = color; 
            break;
        case ActionType::DOWN:
            rect = { xs-ARROW_WIDTH/2, ys, ARROW_WIDTH, CELL_SIZE};
            // Define the three corners relative to a center point (x, y)
            // Bottom Vertex
            vertices[0].position = { xd, yd + arrowHeadSize };
            vertices[0].color = color; 

            // Top Left (Green)
            vertices[1].position = { xd - arrowHeadSize, yd - arrowHeadSize };
            vertices[1].color = color; 

            // Top Right (Blue)
            vertices[2].position = { xd + arrowHeadSize, yd - arrowHeadSize };
            vertices[2].color = color; 
            break;
        case ActionType::LEFT:
            rect = { xd, yd-ARROW_WIDTH/2, CELL_SIZE, ARROW_WIDTH};
            // Define the three corners relative to a center point (x, y)
            // Left Vertex
            vertices[0].position = { xd - arrowHeadSize, yd };
            vertices[0].color = color; 

            // Bottom  (Green)
            vertices[1].position = { xd + arrowHeadSize, yd + arrowHeadSize };
            vertices[1].color = color; 

            // Top (Blue)
            vertices[2].position = { xd + arrowHeadSize, yd - arrowHeadSize };
            vertices[2].color = color; 
            break;
        case ActionType::RIGHT:
            rect = { xs, ys-ARROW_WIDTH/2, CELL_SIZE, ARROW_WIDTH};
            // Define the three corners relative to a center point (x, y)
            // right Vertex
            vertices[0].position = { xd + arrowHeadSize, yd };
            vertices[0].color = color; 

            // Bottom  (Green)
            vertices[1].position = { xd - arrowHeadSize, yd + arrowHeadSize };
            vertices[1].color = color; 

            // Top (Blue)
            vertices[2].position = { xd - arrowHeadSize, yd - arrowHeadSize };
            vertices[2].color = color; 
            break;
        default:
            return;
        }
        SDL_RenderGeometry(renderer, NULL, vertices, 3, NULL, 0);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderRect(renderer, &rect);
    }

    void Path::addWayPoint(WayPoint point)
    {
        m_path.push_back(point);
    }

    void Path::render(SDL_Renderer* renderer)
    {
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