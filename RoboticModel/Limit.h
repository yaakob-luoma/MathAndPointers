#ifndef LIMIT_H
#define LIMIT_H

template< class T >
class Limit
{
public:
    Limit( T* minPtr = nullptr, T* maxPtr = nullptr );
    Limit( const Limit& copy );
    ~Limit();
    Limit& operator=( const Limit& assign );
    bool operator==( const Limit& rhs );

    bool isSet();

    T *getMin() const;
    void setMin(T *value);

    T *getMax() const;
    void setMax(T *value);

private:
    T* minPtr;
    T* maxPtr;

};

template< class T >
Limit<T>::Limit( T* minPtr, T* maxPtr )
{
    setMin( minPtr );
    setMax( maxPtr );
}

template< class T >
Limit<T>::Limit( const Limit<T>& copy )
    : minPtr( copy.getMin() )
    , maxPtr( copy.getMax() )
{

}

template< class T >
Limit<T>::~Limit()
{

}

template< class T >
Limit<T>& Limit<T>::operator=( const Limit<T>& assign )
{
    minPtr = assign.getMin();
    maxPtr = assign.getMax();
}

template< class T >
bool Limit<T>::operator==( const Limit<T>& rhs )
{
    return minPtr == rhs.getMin()
        && maxPtr == rhs.getMax()
         ? true : false;
}

template< class T >
bool Limit<T>::isSet()
{
    return minPtr != nullptr
        && maxPtr != nullptr
         ? true : false;

}

template< class T >
T* Limit<T>::getMin() const
{
    return minPtr;
}

template< class T >
void Limit<T>::setMin(T *value)
{
    if ( !( maxPtr != nullptr && *value >= * maxPtr ) )
    {
        minPtr = value;
    }
}

template< class T >
T* Limit<T>::getMax() const
{
    return maxPtr;
}

template< class T >
void Limit<T>::setMax(T *value)
{
    if ( !( minPtr != nullptr && *value <= * minPtr ) )
    {
        maxPtr = value;
    }
}

#endif // LIMIT_H
