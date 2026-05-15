#include "GridWorld/PathArrow.hpp"

namespace Grid
{
    PathArrow::PathArrow(const WayPoint& wp, SDL_FColor color, float cellSize)
    {
        mcolor = color;
        float xs = wp.src.x * cellSize + cellSize/2;
        float ys = wp.src.y * cellSize + cellSize/2;
        float xd = wp.dest.x * cellSize + cellSize/2;
        float yd = wp.dest.y * cellSize + cellSize/2;
        float xdiff = (xd-xs);
        float ydiff = (yd-ys);
        ArrowHeight = std::sqrt(xdiff*xdiff + ydiff*ydiff);
        ArrowAngle = std::atan2(ydiff,xdiff);
        BaseHeight = 2*ArrowHeight/3;
        ArrowWidth = ArrowHeight/1.5; 
        BaseWidth = ArrowWidth/3;
        
        // pi over two because arrow is aligned with the arrow y axis
        float ctheta = std::cos(3.14159/2 - ArrowAngle);
        float stheta = std::sin(3.14159/2 - ArrowAngle);

        std::vector<SDL_FPoint> points;
        float x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8;
        x1 = 0; y1 = 0;
        x2 = x1 + BaseWidth/2;
        y2 = y1; x3 = x2;
        y3 = y2 + BaseHeight;
        x4 = x3 + (ArrowWidth/2-BaseWidth);
        y4 = y3;
        x5 = x1; y5 = ArrowHeight;
        x8 = 0 - BaseWidth/2; y8 = 0;
        x7 = x8; y7 = y3;
        x6 = x7 - (ArrowWidth/2-BaseWidth);
        y6 = y7;

        //points.push_back({x1, y1});
        points.push_back({x2, y2});
        points.push_back({x3, y3});
        points.push_back({x4, y4});
        points.push_back({x5, y5});
        points.push_back({x6, y6});
        points.push_back({x7, y7});
        points.push_back({x8, y8});

        for (int i = 0; i < 7; i++)
        {
            SDL_FPoint p = points.at(i);
            v[i].position = {xs+(-ctheta*p.x+stheta*p.y), ys+(stheta*p.x+ctheta*p.y)};
            v[i].color = mcolor;
        }
    }

    SDL_Vertex* PathArrow::getVertices() {return v;}
    
    int* PathArrow::getIndices() {return indices;}

    size_t PathArrow::getVertexCount() {return 7;}

    size_t PathArrow::getIndexCount() {return 9;}
}