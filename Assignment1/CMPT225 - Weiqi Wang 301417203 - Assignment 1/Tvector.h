#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>
using namespace std;

template <typename Object>
class TVector
{
  public:
    TVector( )
      {  
         theSize = 0 ; 
         theCapacity = 10 ;
         objects = new Object[ theCapacity ]; 
      }
      
    ~TVector( )
      { delete [ ] objects; }

    bool empty( ) const  { return size( ) == 0; }
    int size( ) const { return theSize; }

    Object & operator[]( int index )
    {
        return objects[ index ];
    }

    const Object & operator[]( int index ) const
    {
        return objects[ index ];
    }

    void reserve( int newCapacity )
    {
        if( newCapacity > theSize ){

           Object *newArray = new Object[ newCapacity ];
           for( int k = 0; k < theSize; ++k ){
                 newArray[ k ] =  objects[ k ] ;
           }
           theCapacity = newCapacity;
           Object * temp = objects ; 
           objects = newArray ;
           delete [ ] temp ;
        }
    }

    // Stacky stuff
    void push_back( const Object & x )
    {
        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = x ;
    }

    void pop_back( )
    {
        --theSize;
    }

    void display() const 
    {
        cout << "size=" << theSize << endl;

        cout << "< " ;
        for( int i = 0; i < theSize ; ++i ){
           cout  << i << "=" << objects[i] << ", " ;
        }
        cout << " >" << endl ;
    }

    void ddisplay() const 
    {
        cout << "capacity = " << theCapacity << ", size=" << theSize << endl;

        cout << "[ " ;
        for( int i = 0; i < theCapacity ; ++i ){
           cout  << i << "=" << objects[i] << ", " ;
        }
        cout << " ]" << endl ;
    }

  private:
    int theSize;
    int theCapacity;
    Object * objects;
};

#endif
