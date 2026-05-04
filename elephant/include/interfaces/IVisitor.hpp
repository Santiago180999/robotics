#ifndef IVISITOR_HPP
#define IVISITOR_HPP

#include "concrete/Node.hpp"
#include "concrete/Frame.hpp"

class IVisitor
{
    public: 

    virtual ~IVisitor() = default;

    virtual void Visit(Frame& frame) = 0;

};


#endif