#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include "Vector.h"

using namespace std;

template <typename Object>
class Deque 
{
  public:
    Deque()
      {  
         theCapacity = 8 ;
         // objects is an array, the type is Object
         // For example, Deque<int> deque, then objects is an int array
         objects = new Object[ theCapacity ];
         theSize = 0 ;
         front = 0 ;
         back = 0 ;
      }
      
    ~Deque( )
      { delete [ ] objects; }

    bool empty( ) const  { return size( ) == 0; }
    int size( ) const { return theSize; }
    void clear( ){
        // remove all contents and reset the capacity to it's initial value 
        // 
        // Implement this...
        delete [] this->objects;
        this->theCapacity = 8;
        this->objects = new Object[ theCapacity ]; 
        this->theSize = 0;
        this->front = 0; 
        this->back = 0; 
    }

    void reserve( int newCapacity )
    {
        // change the capacity to newCapacity 
        // (provided it is larger than the current size)
        // 
        // Implement this...
        if(newCapacity >= this->theSize) {
            Object *tempObjects;
            tempObjects = new Object[newCapacity];
            for(int i = 0; i < this->theCapacity; i++) {
                tempObjects[i] = this->objects[i];
            }
            delete [] this->objects;
            this->objects = tempObjects;

            // this->objects[newCapacity];
            this->theCapacity = newCapacity;
            // Reset the back to prevent some error
            this->back = this->front + this->size();
        }
    }

    // Operations 

    void enqueue( const Object & x )// Insert a new object at the back 
    {
        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
        objects[ back ] = x ;
        back = (back+1) % theCapacity ;
        theSize++ ;
    }

    void jump( const Object & x )// Insert a new object at the front
    {
        // Implement this 
        if(this->front > 0) {
            this->objects[this->front-1] = x;
            this->front--;
            this->theSize++;
        } else {
            if(theSize == theCapacity){ reserve(2 * theCapacity + 1); };
            // Uses a reverse for loop to prevent use temporary variable
            for(int i = this->front + this->size() - 1; i >= this->front; i--) {
                this->objects[i+1] = this->objects[i];
            }
            this->back++;
            this->objects[this->front] = x;
            this->theSize++;
        }
    }

    Object dequeue( )// Remove and return the object at the front 
    {
        theSize--;
        Object temp = objects[front];
        front = (front+1) % theCapacity ;
        return temp ;
    }

    Object eject( )// Remove and return the object at the back 
    {
        // Implement this
        if (this->theSize <= 0 || this->front < 0) {
            // return 0 in the type of Object
            return static_cast<Object>(0);
        }
        Object temp = this->objects[this->front+this->size()-1];
        this->theSize--;
        this->back--;
        return temp;
    }

    void display() const // print out the contents of the deque
    {
       // Implement this.  The output should be similar to that 
       // used in the Vector and Stack classes provided.

       cout << "[";
        for(int i = this->front; i < this->front + this->size(); i++) {
          cout << this->objects[i];
          if(i != this->front + this->size() - 1) {
            cout << ",";
          }
        }
        cout << "]" << endl;
    }

    void ddisplay() const // print out the contents of the objects 
    // array, and relevant variables, for debugging or verifying 
    // correctness. 
    {
        // Implement this.  The output should be in the style used in 
        // Vector and Stack classes provided.
        cout << "theCapacity: " << this->theCapacity << endl;
        cout << "theArrey is in address: "<< &this->objects << endl;
        cout << "theArrey: ";
        this->display();
        cout << "theSize: " << this->theSize << endl;
        cout << "front: " << this->front << endl;
        cout << "back: " << this->back << endl;
    }

    Object& operator[] (int index){
        if(this->front <= index <= this->front + this->size()) {
            return this->objects[index];
        }
    }


  private:
    int theSize;
    int front;
    int back;
    int theCapacity;
    Object * objects;
};

#endif
