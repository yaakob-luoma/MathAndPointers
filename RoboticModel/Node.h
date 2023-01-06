#ifndef NODE_H
#define NODE_H

template< class T>
class Node
{
public:
    Node(const T& data = T(), Node<T>* next = nullptr );
    Node( const Node& copy);
    ~Node();
    Node& operator=( const Node& assign );

    T getData() const;
    void setData(const T &value);

    Node *getNext() const;
    void setNext(Node *value);

private:
    T data;
    Node* next;
};

template<class T>
Node<T>::Node( const T& data, Node<T>* next )
    : data( data )
    , next( next )
{

}

template<class T>
Node<T>::Node( const Node& copy )
    : data( copy.getData() )
    , next( copy.getNext() )
{

}

template< class T>
Node<T>::~Node()
{

}

template< class T>
Node<T>& Node<T>::operator=( const Node& assign )
{
    data = assign.getData();
    next = assign.getNext();
    return *this;
}

template< class T>
T Node<T>::getData() const
{
    return data;
}

template< class T>
void Node<T>::setData(const T &value)
{
    data = value;
}

template< class T>
Node<T>* Node<T>::getNext() const
{
    return next;
}

template< class T>
void Node<T>::setNext(Node *value)
{
    next = value;
}

#endif // NODE_H
