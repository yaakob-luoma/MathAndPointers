#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "Node.h"

template< class T>
class SingleLinkedList
{
public:
    SingleLinkedList(const Node<T>* head = nullptr );
    SingleLinkedList( const SingleLinkedList& copy);
    ~SingleLinkedList();
    SingleLinkedList& operator=( const SingleLinkedList& assign );

    T get( unsigned int index );
    T set( unsigned int index, T item );
    bool add( T item );
    bool add( unsigned int index, T item );
    int search( T item );
    bool addFirst( const T& item );
    bool addAfter( const Node<T>& node, T item);
    bool removeAfter( const Node<T>& node);
    bool removeFirst();

    Node<T> *getHead() const;
    void setHead(Node<T> *value);

    unsigned int getSize() const;

private:
    Node<T>* head;
    unsigned int size;
};

template< class T>
SingleLinkedList<T>::SingleLinkedList(const Node<T>* head )
    : head( head )
{

}

template< class T>
SingleLinkedList<T>::SingleLinkedList( const SingleLinkedList& copy)
    : head( copy.getHead )
{

}

template< class T>
SingleLinkedList<T>::~SingleLinkedList()
{

}

template< class T>
SingleLinkedList<T>& SingleLinkedList<T>::operator=( const SingleLinkedList& assign )
{
    head = assign.getHead();
    return *this;
}

template< class T>
T SingleLinkedList<T>::get( unsigned int index )
{
    T result;
    if ( index >= size )
    {
        //index outofbounds
    }
    else
    {
        Node<T>* iter;
        iter = head;
        for( unsigned int i = 0; i < index; i++ )
        {
            iter = head->getNext();
        }
        result = iter->getData();
    }
    return result;
}

template< class T>
T SingleLinkedList<T>::set( unsigned int index, T item )
{
    T result;
    if ( index >= size )
    {
        //index outofbounds
    }
    else
    {
        Node<T>* iter;
        iter = head;
        for( unsigned int i =0; i < index; i++ )
        {
            iter = head->getNext();
        }
        iter->setData( item );
        result = iter->getData();
    }
    return result;
}

template< class T >
bool SingleLinkedList<T>::add( T item )
{
    if ( size == 0 )
    {
        head->setData( item );
    }
    else
    {
        Node<T>* iter;
        iter = head;
        for( unsigned int i = 0; i < size; i++ )
        {
            iter = head->getNext();
        }
        iter->setNext( item );
    }
    size++;
    return true;
}

template< class T>
bool SingleLinkedList<T>::add( unsigned int index, T item )
{
    bool isAdded;
    if ( index >= size )
    {
        // index out of bounds
        isAdded = false;
    }
    else
    {
        size++;
        isAdded = true;

        if ( index == 0 )
        {
            addFirst( item );
        }
        else
        {
            Node<T>* iter;
            iter = head;
            for( unsigned int i = 0; i < ( index - 1 ); i++ )
            {
                iter = iter->getNext();
            }
            Node<T>* tail;
            tail = iter->getNext();
            iter->setNext(item, tail);
        }
    }
    return isAdded;
}

template< class T >
int SingleLinkedList<T>::search( T item )
{
    int result;
    if ( size == 0 )
    {
        // nothing to search
        result = -1;
    }
    else
    {
        Node<T>* iter;
        iter = head;
        bool isFound = false;
        unsigned int index = 0;
        while( !isFound && index < size )
        {
            if ( iter->getData() == item )
            {
                isFound = true;
                result = index;
            }
            else
            {
                index++;
            }
        }
        if ( !isFound )
        {
            result = -1;
        }
    }
    return result;
}

template< class T>
bool SingleLinkedList<T>::addFirst( const T& item )
{
    head = new Node<T>(item, head);
    size++;
}

template< class T>
bool SingleLinkedList<T>::addAfter( const Node<T>& node, T item)
{
    node.setNext( new Node<T>(item, node.getNext() ) );
    size++;
}

template< class T>
bool SingleLinkedList<T>::removeAfter( const Node<T>& node)
{
    Node<T> temp = node.getNext();
    node.setNext( temp.getNext() );
    size--;
}

template< class T>
bool SingleLinkedList<T>::removeFirst()
{
    if( head != nullptr )
    {
        Node<T> temp = *head;
        head = head->getNext();
        size--;
    }

}

template< class T>
Node<T>* SingleLinkedList<T>::SingleLinkedList::getHead() const
{
    return head;
}

template< class T>
void SingleLinkedList<T>::SingleLinkedList::setHead(Node<T> *value)
{
    head = value;
}

template< class T>
unsigned int SingleLinkedList<T>::getSize() const
{
    return size;
}

#endif // SINGLELINKEDLIST_H
