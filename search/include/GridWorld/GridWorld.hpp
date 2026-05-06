#ifndef GRIDWORLD_HPP
#define GRIDWORLD_HPP

#include "Common.hpp"
#include "Path.hpp"

namespace Grid
{
    struct CursorLocation
    {
        Point curr, last;
        CellType cellType;

        CellType moveCursor(Point next, CellType nextType)
        {
            last = curr;
            curr = next;

            CellType prevType = cellType;
            cellType = nextType;
            return prevType;
        }
    };

    class GridWorld : IVisual
    {

        public:
        GridWorld(int gridSize);

        GridWorld(Grid2D& grid);

        const Grid2D& getGrid();

        void handleInput(const SDL_Event& e);

        void render(SDL_Renderer* renderer) override;

        Point setStartCell(Point loc);

        Point setGoalCell(Point loc);

        Point takeAction(ActionType action, Point loc);

        bool isCellEmpty(Point loc);

        bool isCellGoal(Point loc);

        bool isCellInbounds(Point loc);

        ActionType ACTIONS[4] = {ActionType::UP, ActionType::DOWN, ActionType::LEFT, ActionType::RIGHT};

        protected:
        void setCellType(Point loc, CellType type);

        private:
        Grid2D m_grid;
        Point m_agentPos;
        int m_gridSize;

    };
}
#endif