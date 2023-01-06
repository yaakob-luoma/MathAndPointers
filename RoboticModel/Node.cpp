#include "Node.h"

Node::Node()
{

}

T Node::getData() const
{
    return data;
}

void Node::setData(const T &value)
{
    data = value;
}

Node *Node::getNext() const
{
    return next;
}

void Node::setNext(Node *value)
{
    next = value;
}
