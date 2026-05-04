#include "Node.hpp"

Node::Node() 
{
    parent = nullptr;
    firstChild = nullptr;
    prevSibling = nullptr;
    nextSibling = nullptr;
}

Node::Node(Node& other) 
{
    parent = other.parent;
    firstChild = other.firstChild;
    prevSibling = other.prevSibling;
    nextSibling = other.nextSibling;
}

Node::~Node()
{
    delete parent;
    delete firstChild;
    delete prevSibling;
    delete nextSibling;
}

Node* Node::GetParent()
{
    return parent;
}

Node* Node::GetPrevSibling()
{
    return prevSibling;
}

Node* Node::GetNextSibling()
{
    return nextSibling;
}

Node* Node::GetFirstChild()
{
    return firstChild;
}

void Node::AddChild()
{
    if (firstChild == nullptr)
    {
        firstChild = new Node(); // create new node
        return;
    }

    Node* pFc = firstChild; // hold current first child
    firstChild = new Node(); // new first child
    pFc->prevSibling = firstChild; // add new first child to be before in the existing child
    firstChild->nextSibling = pFc; // add the previous first child to the next sibling of the new first child

}

void Node::DeleteChild() // TODO
{
    Node* p_SecondChild = firstChild->nextSibling;

}
