#ifndef PATHARROW_HPP
#define PATHARROW_HPP

#include "IShape.hpp"
#include <cmath>
#include <numbers>

namespace Grid
{
class PathArrow: public IShape
    {
        public:
        // arrow coordinate frame is x left, y up, +ve CCW
        PathArrow(const WayPoint& wp, SDL_FColor color, float cellSize);

        SDL_Vertex* getVertices() override;

        int* getIndices() override;

        size_t getVertexCount() override;

        size_t getIndexCount() override;

        private:
        SDL_Vertex v[7];
        SDL_FColor mcolor;
        int indices[9] = {6, 0, 1,  1, 5, 6,  2, 3, 4};
        float ArrowAngle = 0;
        float BaseHeight = 0;
        float BaseWidth = 0;
        float ArrowHeight = 0;
        float ArrowWidth = 0; 
    };
}

#endif