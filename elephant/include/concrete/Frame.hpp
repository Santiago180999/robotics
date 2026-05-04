#ifndef FRAME_HPP
#define FRAME_HPP

#include "Node.hpp"

class Frame : Node
{
    public:
    /// @brief 
    Frame();

    /// @brief 
    /// @param other Frame to copy
    Frame(Frame& other);

    /// @brief 
    ~Frame();

    /// @brief 
    void UpdateLocalPose();

    /// @brief 
    void UpdateGlobalPose();


    private:
    int Rotation[9];
    int Translation[3]; 

};

#endif