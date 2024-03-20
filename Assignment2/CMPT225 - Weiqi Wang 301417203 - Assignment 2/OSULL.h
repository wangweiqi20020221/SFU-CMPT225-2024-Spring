/* Ordered Set Implemented in an Unrolled (Doubly)-Linked List */
// File: OSULL.h

#include <iostream>
#include <cstring>
using namespace std;


template <typename T, int initNodeCapacity = 10 > 
class OSULL
{
public:
   OSULL(){

      // set the node capacity  
      nodeCapacity = initNodeCapacity ;

      // make the front and back dummy nodes 
      front = new Node( nullptr, nullptr, nodeCapacity );
      back = new Node( front, nullptr, nodeCapacity );
      front->next = back;

      size = 0 ;
      nodeCount = 0 ; 
   }
   ~OSULL(){
      Node * cursor = front ;
      while( cursor != nullptr ){
         Node * current = cursor ;
         cursor = cursor-> next ;
         delete  current ;
      }
   }
   bool isEmpty(){ return size==0 ;}
   int get_size(){ return size ;}

   bool insert(T item){
      // inserts item into the list, if it is not there already
      // returns true if inserted; false if it was already there
      //
      // IMPLEMENT THIS
      //
      if(this->find(item)) {
         return false;
      }
      // Count how much nodes are require to store all the items
      int nodeAmounts = (this->get_size() + 1) / this->nodeCapacity;
      if((this->get_size() + 1) % this->nodeCapacity > 0) {
         nodeAmounts++;
      }
      if(nodeAmounts > this->nodeCount) {
         // Create a new empty node when the current nodes amount are less than the amount that required
         Node * newNode = new Node(this->back->prev, this->back, this->nodeCapacity);
         newNode->prev->next = newNode;
         this->back->prev = newNode;
         this->nodeCount++;
         // Evenly distributed items to every nodes
         Node * cursor = this->front->next;
         int nodeIndex = 0;
         while(cursor != this->back) {
            int nodeSizeRequire = this->size / this->nodeCount;
            if(nodeIndex < this->size % this->nodeCount) {
               nodeSizeRequire++;
            }
            while(cursor->getSize() > nodeSizeRequire) {
               Node * cursorTemp = this->back->prev;
               while(cursorTemp != cursor) {
                  cursorTemp->insert(cursorTemp->prev->getMax());
                  cursorTemp->prev->remove(cursorTemp->prev->getMax());
                  cursorTemp = cursorTemp->prev;
               }
            }
            cursor = cursor->next;
            nodeIndex++;
         }
      }
      // Insert item to its position
      if(this->isEmpty()) {
         this->front->next->insert(item);
         this->size++;
         return true;
      }
      Node* cursor = this->front->next;
      int nodeIndex = 0;
      while(cursor != this->back->prev && item > cursor->getMax()) {
         cursor = cursor->next;
         nodeIndex++;
      }
      Node* cursorTemp = this->front->next;
      int nodeIndexTemp = 0;
      int nodeSizeRequireTemp = (this->get_size() + 1) / this->nodeCount;
      if(nodeIndexTemp < (this->get_size() + 1) % this->nodeCount) {
         nodeSizeRequireTemp++;
      }
      while(cursorTemp->getSize() == nodeSizeRequireTemp) {
         cursorTemp = cursorTemp->next;
         nodeIndexTemp++;
         nodeSizeRequireTemp = (this->get_size() + 1) / this->nodeCount;
         if(nodeIndexTemp < (this->get_size() + 1) % this->nodeCount) {
            nodeSizeRequireTemp++;
         }
      }
      if(nodeIndex < nodeIndexTemp) {
         Node* cursorTemp2 = cursorTemp;
         while(cursorTemp2 != cursor) {
            cursorTemp2->insert(cursorTemp2->prev->getMax());
            cursorTemp2->prev->remove(cursorTemp2->prev->getMax());
            cursorTemp2 = cursorTemp2->prev;
         }
      } else if(nodeIndex > nodeIndexTemp) {
         Node* cursorTemp2 = cursor;
         while(cursorTemp2 != cursorTemp) {
            cursorTemp2->prev->insert(cursorTemp2->getMin());
            cursorTemp2->remove(cursorTemp2->getMin());
            cursorTemp2 = cursorTemp2->prev;
         }
      }
      cursor->insert(item);
      this->size++;
      return true;
   ; }

   bool find(T item){ 
      // searches for item in the list
      // returns true if found; false otherwise 
      //
      // IMPLEMENT THIS 
      //
      
      Node * cursor = this->front->next;
      while(cursor != this->back) {
         if(item >= cursor->getMin() && item <= cursor->getMax()) {
            return cursor->find(item);
         }
         cursor = cursor-> next;
      }
      return false;
   ; }

   bool remove(T item){
      // removes item from the list 
      // returns false if the item was not there; true if it was
      //
      // IMPLEMENT THIS
      //
      
      // Remove the item
      Node * cursor = this->front->next;
      while(cursor != this->back->prev && item > cursor->getMin()) {
         cursor = cursor->next;
      }
      if(item < cursor->getMin()) {
         return false;
      }
      if(!cursor->remove(item)) {
         return false;
      }
      this->size--;
      // Count how much nodes are require to store all the items
      int nodeAmounts = (this->size) / this->nodeCapacity;
      if((this->size) % this->nodeCapacity != 0) {
         nodeAmounts++;
      }
      if(this->nodeCount > nodeAmounts) {
         // Remove all items from the last node and insert these items in previous nodes
         cursor = this->front->next;
         while(cursor != this->back->prev) {
            while(cursor->getSize() < cursor->getCapacity()) {
               Node * cursorTemp = cursor;
               while(cursorTemp != this->back->prev) {
                  cursorTemp->insert(cursorTemp->next->getMin());
                  cursorTemp->next->remove(cursorTemp->next->getMin());
                  cursorTemp = cursorTemp->next;
               }
            }
            cursor = cursor->next;
         }
         Node* tempLastNode = this->back->prev->prev;
         delete[] this->back->prev->data;
         delete this->back->prev;
         this->back->prev = tempLastNode;
         tempLastNode->next = this->back;
         return true;
      }
      // Evenly distributed items to every nodes
      cursor = this->front->next;
      int nodeIndex = 0;
      while(cursor != back) {
         int nodeSizeRequire = (this->size) / this->nodeCount;
         if(nodeIndex < (this->size) % this->nodeCount) {
            nodeSizeRequire++;
         }
         if(cursor->getSize() < nodeSizeRequire) {
            cursor->insert(cursor->next->getMin());
            cursor->next->remove(cursor->next->getMin());
         } else if (cursor->getSize() > nodeSizeRequire) {
            Node * cursorTemp = this->back->prev;
            int nodeIndexTemp = this->size - 1;
            while(cursorTemp != cursor) {
               int nodeSizeRequireTemp = (this->size) / this->nodeCount;
               if(nodeIndexTemp < (this->size) % this->nodeCount) {
                  nodeSizeRequireTemp++;
               }
               if(cursorTemp->getSize() < nodeSizeRequireTemp) {
                  cursorTemp->insert(cursorTemp->prev->getMax());
                  cursorTemp->prev->remove(cursorTemp->prev->getMax());
               }
               cursorTemp = cursorTemp->prev;
               nodeIndexTemp--;
            }
         }
         cursor = cursor->next;
         nodeIndex++;
      }
      return true;
   ; }

   T getMin(){// returns the minimum item in the lise
      // requires: size not 0 
      //
      // IMPLEMENT THIS 
      //
      if(this->front->next == this->back) {
         return NULL;
      }
      return this->front->next->getMin();
    ; } 

   T getMax(){// returns the maximum item in the list
      // requires: size not 0 
      //
      // IMPLEMENT THIS
      //
      if(this->back->prev == this->front) {
         return NULL;
      }
      return this->back->prev->getMax();
   ;}

   void display(){
      // prints out the list contents 
      Node * cursor = front-> next ;
      cout << "<" ;
      while( cursor != back ){
         cursor -> display() ; 
         cursor = cursor-> next ;
      }
      cout << " >" ;
   }
      
private:

   class Node{
      public: 
      Node( Node* prev, Node* next, int capacity ){
         // notice that we can use the constructor arguments to 
         // do most o the work of inserting a new node into the list 
         this->prev = prev ;
         this->next = next ;
         this->capacity = capacity ;
         data = new T[capacity] ;
         size = 0 ;
      }
      Node * prev ; // pointer to the next node 
      Node * next ; // pointer to the previous nodes 
      int capacity ; // capacity of this node 
      T * data ; // array of data items in this node 
      int size ; // current number of items in this node
      int getCapacity(){// return the capacity of this node 
         return capacity; 
      }
      int getSize(){// return the number of items in this node
         return size; 
      }
      T getMin(){// return the smallest item in this node
         // requires: this->size not 0 
         return data[0] ; 
      }
      T getMax(){// return the largest item in this node 
         // requires: this->size not 0 
         return data[size-1] ; 
      }
      bool insert(T item){
         // inserts item into this node if it was not already there 
         // returns true if the item was inserted, false otherwise 
	      //
         // IMPLEMENT THIS 
	      //
         if(this->getSize() == this->getCapacity()) {
            return false;
         }
         int index = 0;
         while(index < this->getSize() && this->data[index] < item) {
            index++;
         }
         if(this->data[index] == item) {
            return false;
         }
         this->data[this->getSize()] = item;
         this->size++;
         for(int index = this->getSize() - 1; index > 0; index--) {
            if(this->data[index-1] > this->data[index]) {
               T tempItem = this->data[index];
               this->data[index] = this->data[index-1];
               this->data[index-1] = tempItem;
            } else {
               return true;
            }
         }
         return true;
      ;}
      bool find(T item){
         // searches for item in this node 
         // returns true if found, false otherwise 
	      //
         // IMPLEMENT THIS
	      //
         for(int index = 0; index < this->size; index++) {
            if(item == this->data[index]) {
               return true;
            } else if(item < this->data[index]) {
               return false;
            }
         }
         return false;
      ;}
      bool remove(T item){
         // remove item from this node
         // returns true if the item was removed, false otherwise 
	      //
         // IMLEMENT THIS
	      //
         if(item < this->getMin() || item > this->getMax()) {
            return false;
         }
         for(int index = 0; index < this->getSize(); index++) {
            if(this->data[index] == item) {
               this->data[index] = NULL;
               for(int tempIndex = index; tempIndex < this->size - 1; tempIndex++) {
                  T tempItem = this->data[tempIndex + 1];
                  this->data[tempIndex + 1] = this->data[tempIndex];
                  this->data[tempIndex] = tempItem;
               }
               this->size--;
               return true;
            } else if(this->data[index] > item) {
               return false;
            }
         }
         return false;
      ;}
      void display(){// print the contents of this list 
         // 
         // IMPLEMENT THIS
	      //
	      //
         cout << "[";
         if(this->getSize() > 0) {
            for(int index = 0; index < this->size; index++) {
            cout << this->data[index];
            if(index != this->size-1) {
               cout << ",";
            }
         }
         }
         cout << "]";
      ;} 
   };

   int size ; // current number of items 
   int nodeCount ; // current number of nodes 
   int nodeCapacity ; // capacity to assign to new nodes 
   Node * front ; // pointer to front dummy node 
   Node * back ;  // pointer to back dummy node 
};
