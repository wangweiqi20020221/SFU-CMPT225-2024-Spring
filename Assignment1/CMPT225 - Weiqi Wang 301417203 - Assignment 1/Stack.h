#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename Object>
class Stack 
{
  public:
    Stack( int initSize = 0 )
      {  
         theSize = 0 ;
         theCapacity = 10 ; 
         objects = new Object[ theCapacity ]; 
      }
      
    ~Stack( )
      { delete [ ] objects; }

    bool empty( ) const  { return size( ) == 0; }
    int size( ) const { return theSize; }

    void reserve( int newCapacity )
    {
        if( newCapacity > theSize ){

           Object * newArray = new Object[ newCapacity ];
           for( int k = 0; k < theSize; ++k ){
                 newArray[ k ] = objects[ k ] ;
           }
           Object * temp = objects ;  
           objects = newArray ;
           delete [] temp ;
           theCapacity = newCapacity;
        }
    }

    // Operations 
    void push( const Object & x )
    {
        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = x ;
    }

    Object pop( )
    {
        --theSize;
        return objects[ theSize ] ; 
    }

    void display() const 
    {
        cout << "size=" << theSize << std::endl;

        cout << "< " ;
        for( int i = 0; i < theSize ; ++i ){
           cout << i << "=" << objects[i] << ", " ;
        }
        cout << " >" << endl;
    }

    void ddisplay() const 
    {
        cout << "capacity= " << theCapacity << ", size=" << theSize << std::endl;

        cout << "[ " ;
        for( int i = 0; i < theCapacity ; ++i ){
           cout << i << "=" << objects[i] << ", " ;
        }
        cout << " ]" << endl;
    }

  private:
    int theSize;
    int theCapacity;
    Object * objects;
};

#endif
