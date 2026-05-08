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

    enum MovementType
    {
        ORTHOGONAL,
        DIAGONAL
    };

    class GridWorld : IVisual
    {
        public:

        // Functions im confident belong here:
        GridWorld(Grid2D& grid, MovementType type);

        const Grid2D& getGrid();

        void render(SDL_Renderer* renderer) override;

        /// @brief Given an action and a point, return the next point. If next point is not valid, or point passed is not valid, returns the original point 
        /// @param action Action to take 
        /// @param loc Starting point
        /// @return New point
        Point takeAction(ActionType action, Point loc);

        bool isCellValid(Point loc);

        const std::vector<ActionType>& getActions();

        // functions im not confident belong here:
        bool setStartCell(Point loc);

        bool setGoalCell(Point loc);  

        bool isCellGoal(Point loc);
        
        void handleInput(const SDL_Event& e);

        protected:
        
        void setCellType(Point loc, CellType type);

        bool isCellEmpty(Point loc);
        
        bool isCellInbounds(Point loc);

        bool isValidAction(ActionType action);

        void setActionList(MovementType type);

        private:
        Point m_agentPos;

        Grid2D m_grid;
        int m_gridSize;
        std::vector<ActionType> m_actions;
    };
}
#endif