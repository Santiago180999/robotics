#ifndef ISHAPE_HPP
#define ISHAPE_HPP

#include "Common.hpp"

class IShape
{
    public:
    virtual ~IShape() = default;
    virtual SDL_Vertex* getVertices() = 0;
    virtual int* getIndices() = 0;
    virtual size_t getVertexCount() = 0;
    virtual size_t getIndexCount() = 0;

};

#endif