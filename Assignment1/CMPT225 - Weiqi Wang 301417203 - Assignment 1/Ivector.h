#ifndef IVECTOR_H
#define IVECTOR_H

#include <iostream>
using namespace std;

class IVector
{
  public:
    IVector( )
      {  
         theSize = 0 ;
         theCapacity = 10 ;
         objects = new int[ theCapacity ]; 
      }
      
    ~IVector( )
      { delete [ ] objects; }

    bool empty( ) const  { return size( ) == 0; }
    int size( ) const { return theSize; }

    int & operator[]( int index ) // see text p.46 for why two operator[] definitions.
    {
        return objects[ index ];
    }

    const int & operator[]( int index ) const
    {
        return objects[ index ];
    }

    void reserve( int newCapacity )
    {
        if( newCapacity > theSize ){

           int *newArray = new int[ newCapacity ];
           for( int k = 0; k < theSize; ++k ){
                 newArray[ k ] = objects[ k ] ;
           }
           theCapacity = newCapacity;
           int * temp = objects ;
           objects = newArray ;
           delete [ ] temp ;
        }
    }

    // Stacky stuff
    void push_back( const int & x )
    {
        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = x;
    }

    void pop_back( )
    {
        --theSize;
    }

    void display() const 
    {
        cout << "size=" << theSize << endl;

        cout << " < " ;
        for( int i = 0; i < theSize ; i++ ){
           cout << i << "=" << objects[i] << ", " ;
        }
        cout << ">" << endl;
    }

    void ddisplay() const
    {
        cout << "capacity=" << theCapacity << ", size=" << theSize << endl;

        cout << "[ " ;
        for( int i = 0; i < theCapacity ; i++ ){
           cout << i << "=" << objects[i] << ", " ;
        }
        cout << "] " << endl;
    }
        

  private:
    int theSize;
    int theCapacity;
    int * objects;
};

#endif
