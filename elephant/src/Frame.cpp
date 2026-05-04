#include "Frame.hpp"

Frame::Frame()
{
    rotation = nullptr;
    translation = nullptr;
}

Frame::Frame(Frame& other)
{
    rotation = other.rotation;
    translation = other.translation;
}

Frame::~Frame()
{
    delete rotation;
    delete translation;
}




