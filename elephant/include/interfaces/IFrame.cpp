#ifndef IFRAME_HPP
#define IFRAME_HPP

#include "IVisitor.hpp"

using Pose = KinematicLib::Transformation;

class IFrame
{
    public:
    
    virtual ~IFrame() = default;

    virtual Pose GetGlobalPose() = 0;
    
    virtual Pose GetLocalPose() = 0;

    virtual void UpdateGlobalPose(IVisitor *visitor) = 0

    virtual void UpdateLocalPose(IVisitor *visitor) = 0; // not sure i need this to be a visitor

};

#endif