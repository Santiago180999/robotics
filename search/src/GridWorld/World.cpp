#include "GridWorld/World.hpp"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

namespace Grid
{
    World::World(Grid::Grid2D& grid, MovementType type) : m_gridSize(grid.size()), m_grid(grid)
    {
        m_agentPos = {0, 0};
        setActionList(type);
    }

    void World::setActionList(MovementType type)
    {
        switch (type)
        {
        case MovementType::ORTHOGONAL:
            m_actions = {ActionType::INPLACE, ActionType::UP, ActionType::DOWN, ActionType::LEFT, ActionType::RIGHT};
            break;
        case MovementType::DIAGONAL:
            m_actions = {ActionType::INPLACE, ActionType::UP, ActionType::DOWN, ActionType::LEFT, ActionType::RIGHT, ActionType::NORTHEAST, ActionType::NORTHWEST, ActionType::SOUTHEAST, ActionType::SOUTHWEST};
            break;
        default:
            m_actions = {ActionType::INPLACE};
            break;
        }
    }

    const Grid2D& World::getGrid()
    {
        return m_grid;
    }

    void World::handleInput(const SDL_Event& e) {}
/*         if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
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
        } */


    void World::render(SDL_Renderer* renderer) {
        int SCREEN_WIDTH;
        int SCREEN_HEIGHT;
        SDL_GetCurrentRenderOutputSize(renderer, &SCREEN_WIDTH, &SCREEN_HEIGHT);
        float CELL_SIZE = (float)SCREEN_WIDTH / m_gridSize;
        for (int y = 0; y < m_gridSize; ++y) {
            for (int x = 0; x < m_gridSize; ++x) {
                SDL_FRect rect = { x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE };
                
                if (m_grid[y][x] == WALL) SDL_SetRenderDrawColor(renderer, 40, 44, 52, 255);
                else if (m_grid[y][x] == AGENT) SDL_SetRenderDrawColor(renderer, 97, 175, 239, 255);

                else SDL_SetRenderDrawColor(renderer, 240, 240, 240, 255);

                SDL_RenderFillRect(renderer, &rect);
                
                // Draw grid lines
                SDL_SetRenderDrawColor(renderer, 171, 178, 191, 255);
                SDL_RenderDebugText(renderer, x * CELL_SIZE, y * CELL_SIZE, ""); // Placeholder for text if needed
                SDL_RenderRect(renderer, &rect);
            }
        }
    }

    const std::vector<ActionType>& World::getActions()
    {
        return m_actions;
    }


    void World::setCellType(Point loc, CellType type)
    {
        m_grid[loc.y][loc.x] = type;
    }

    Point World::takeAction(ActionType action, Point loc)
    {
        if (!isCellValid(loc) || !isValidAction(action))
        {
            return loc;
        }
        Point out;
        switch (action)
        {
        case ActionType::INPLACE:
            out.x = loc.x;
            out.y = loc.y;
            break;
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
        case ActionType::NORTHEAST:
            out.x = loc.x+1;
            out.y = loc.y-1;
            break;
        case ActionType::NORTHWEST:
            out.x = loc.x-1;
            out.y = loc.y-1;
            break;
        case ActionType::SOUTHEAST:
            out.x = loc.x+1;
            out.y = loc.y+1;
            break;
        case ActionType::SOUTHWEST:
            out.x = loc.x-1;
            out.y = loc.y+1;
            break;
        default:
            return loc;
            break;
        }
        if (isCellValid(out))
        {
            return out;
        }
        else return loc;
    }

    bool World::isValidAction(ActionType action)
    {
        for (auto& x : m_actions)
        {
            if (action == x)
            {
                return true;
            }
        }
        return false;
    }

    bool World::isCellValid(Point loc)
    {
        if (isCellInbounds(loc))
        {
            if (isCellEmpty(loc))
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
        else 
        {
            return false;
        }
    }

    bool World::isCellInbounds(Point loc)
    {
        if (loc.x >= 0 && loc.x < m_gridSize && loc.y >= 0 && loc.y < m_gridSize)
        {
            return true;
        }
        else return false;
    }

    bool World::isCellEmpty(Point loc)
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
}