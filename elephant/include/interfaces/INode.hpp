#ifndef INODE_HPP
#define INODE_HPP

#include "IVisitor.hpp"

class INode
{
    public:
    /// @brief 
    virtual ~INode() = default;

    /// @brief 
    /// @return 
    virtual INode* GetParent() = 0;

    /// @brief 
    /// @return 
    virtual INode* GetPrevSibling() = 0;

    /// @brief 
    /// @return 
    virtual INode* GetNextSibling() = 0;

    /// @brief 
    /// @return 
    virtual INode* GetFirstChild() = 0;
    
};

#endif