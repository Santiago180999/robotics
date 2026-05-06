#include "GridWorld/GridWorld.hpp"
#include <SDL3/SDL_rect.h>

namespace Grid
{
    GridWorld::GridWorld(int gridSize) : m_gridSize(gridSize), m_grid(m_gridSize, std::vector<CellType>(m_gridSize, EMPTY)) {
        m_agentPos = {0, 0};
        m_grid[m_agentPos.y][m_agentPos.x] = AGENT;
    }

    GridWorld::GridWorld(Grid2D& grid) : m_gridSize(grid.size()), m_grid(grid)
    {
        m_agentPos = {0, 0};
    }

    const Grid2D& GridWorld::getGrid()
    {
        return m_grid;
    }

    void GridWorld::handleInput(const SDL_Event& e) {
        if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            float x, y;
            SDL_GetMouseState(&x, &y);
            int gridX = (int)(x / CELL_SIZE);
            int gridY = (int)(y / CELL_SIZE);
            
            if (gridX >= 0 && gridX < m_gridSize && gridY >= 0 && gridY < m_gridSize) {
                if (m_grid[gridY][gridX] == EMPTY) m_grid[gridY][gridX] = WALL;
                else if (m_grid[gridY][gridX] == WALL) m_grid[gridY][gridX] = EMPTY;
            }
        } 
        // TODO: Update to use moveCursor
        else if (e.type == SDL_EVENT_KEY_DOWN) {
            m_grid[m_agentPos.y][m_agentPos.x] = EMPTY;
            if (e.key.key == SDLK_UP && m_agentPos.y > 0) m_agentPos.y--;
            if (e.key.key == SDLK_DOWN && m_agentPos.y < m_gridSize - 1) m_agentPos.y++;
            if (e.key.key == SDLK_LEFT && m_agentPos.x > 0) m_agentPos.x--;
            if (e.key.key == SDLK_RIGHT && m_agentPos.x < m_gridSize - 1) m_agentPos.x++;
            m_grid[m_agentPos.y][m_agentPos.x] = AGENT;
        }
    }

    void GridWorld::render(SDL_Renderer* renderer) {
        for (int y = 0; y < m_gridSize; ++y) {
            for (int x = 0; x < m_gridSize; ++x) {
                SDL_FRect rect = { x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE };
                
                if (m_grid[y][x] == WALL) SDL_SetRenderDrawColor(renderer, 40, 44, 52, 255);
                else if (m_grid[y][x] == AGENT) SDL_SetRenderDrawColor(renderer, 97, 175, 239, 255);
                else if (m_grid[y][x] == START) SDL_SetRenderDrawColor(renderer, 45, 245, 39, 255);

                else if (m_grid[y][x] == GOAL) SDL_SetRenderDrawColor(renderer, 245, 39, 39, 255);

                else SDL_SetRenderDrawColor(renderer, 240, 240, 240, 255);

                SDL_RenderFillRect(renderer, &rect);
                
                // Draw grid lines
                SDL_SetRenderDrawColor(renderer, 171, 178, 191, 255);
                SDL_RenderDebugText(renderer, x * CELL_SIZE, y * CELL_SIZE, ""); // Placeholder for text if needed
                SDL_RenderRect(renderer, &rect);
            }
        }
    }

    void GridWorld::setCellType(Point loc, CellType type)
    {
        m_grid[loc.y][loc.x] = type;
    }

    Point GridWorld::setStartCell(Point loc)
    {
        if (isCellEmpty(loc))
        {
            setCellType(loc, CellType::START);
            return loc;
        }
        else
        {
            Point x;
            for (auto& act : ACTIONS)
            {
                x = takeAction(act, loc);
                if (isCellEmpty(x))
                {
                    setCellType(x, CellType::START);   
                    return x; 
                }
            }
            setStartCell(x);
        }
    }
    
    Point GridWorld::setGoalCell(Point loc)
    {
        if (isCellEmpty(loc))
        {
            setCellType(loc, CellType::GOAL);
            return loc;
        }
        else
        {
            Point x;
            for (auto& act : ACTIONS)
            {
                x = takeAction(act, loc);
                if (isCellEmpty(x))
                {
                    setCellType(x, CellType::GOAL);   
                    return x; 
                }
            }
            setGoalCell(x);
        }
    }

    Point GridWorld::takeAction(ActionType action, Point loc)
    {
        Point out;
        switch (action)
        {
        case ActionType::UP:
            out.x = loc.x; 
            out.y = loc.y-1;
            break;
        case ActionType::DOWN:
            out.x = loc.x; 
            out.y = loc.y+1;
            break;
        case ActionType::LEFT:
            out.x = loc.x-1; 
            out.y = loc.y;
            /* code */
            break;
        case ActionType::RIGHT:
            out.x = loc.x+1;
            out.y = loc.y;
            break;
        default:
            return loc;
            break;
        }
        if (isCellInbounds(out))
        {
            return out;
        }
        else return loc;
    }

    bool GridWorld::isCellInbounds(Point loc)
    {
        if (loc.x >= 0 && loc.x < m_gridSize && loc.y >= 0 && loc.y < m_gridSize)
        {
            return true;
        }
        else return false;
    }

    bool GridWorld::isCellEmpty(Point loc)
    {
        if (m_grid[loc.y][loc.x] == WALL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool GridWorld::isCellGoal(Point loc)
    {
        if (m_grid[loc.y][loc.x] == GOAL)
        {
            return true;
        }
        else
        {
            return false;
        } 
    }
}