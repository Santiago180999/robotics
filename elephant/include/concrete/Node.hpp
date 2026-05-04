#ifndef NODE_HPP
#define NODE_HPP

#include "IVisitor.hpp"

class Node
{
    public:

    /// @brief Default constructor
    Node();

    /// @brief Copy constructor
    /// @param other Node to copy
    Node(Node& other);

    /// @brief Default destructor
    ~Node();

    /// @brief Get the parent node, if any
    /// @return Ptr to parent node, null ptr if none
    Node* GetParent();

    /// @brief Get the previous sibling, if any
    /// @return Ptr to prev sibling node, nullptr if none
    Node* GetPrevSibling();

    /// @brief Get the next sibling, if any
    /// @return Ptr to next sibling node, nullptr if none
    Node* GetNextSibling();

    /// @brief Get the first child, if any
    /// @return Ptr to first child node, nullptr if none
    Node* GetFirstChild();

    /// @brief Add a new child to this node
    void AddChild();

    /// @brief Remove the first child
    void DeleteChild();

    /// @brief 
    /// @param v 
    void AcceptVisitor(IVisitor v);

    private:
    Node* parent;
    Node* firstChild;
    Node* nextSibling;
    Node* prevSibling;
};

#endif