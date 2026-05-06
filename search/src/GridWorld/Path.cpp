#include "GridWorld/Path.hpp"

const int ARROW_WIDTH = 3;
const float EPS = 0.5;

namespace Grid
{
     void drawArrow(SDL_Renderer* renderer, WayPoint& waypoint)
    {
        float arrowHeadSize = 8;
        float xs = waypoint.src.x * CELL_SIZE + CELL_SIZE/2;
        float ys = waypoint.src.y * CELL_SIZE + CELL_SIZE/2;
        float xd = waypoint.dest.x * CELL_SIZE + CELL_SIZE/2;
        float yd = waypoint.dest.y * CELL_SIZE + CELL_SIZE/2;

        SDL_FRect rect;
            
        // Define the three corners relative to a center point (x, y)
        SDL_Vertex vertices[3];
        float alpha = 0;
        switch (waypoint.type)
        {
        case EntryType::FINAL:
            alpha = 0.8;
            break;
        case EntryType::EXPLORE:
            alpha = 0.3;
            break;
        default: 
            break;
        }
        SDL_FColor color = { 0.96, 0.82, 0.15, alpha }; 
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
            break;
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

}