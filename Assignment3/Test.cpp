#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
    Heap<int> heap;
    heap.insert(1);
    cout << "The Heap:";
    heap.display();
    cout << "Height:" << heap.getHeight() << endl;
    cout << "Size:" << heap.getSize() << endl;
    cout << endl;

    heap.insert(2);
    heap.insert(3);
    cout << "The Heap:";
    heap.display();
    cout << "Height:" << heap.getHeight() << endl;
    cout << "Size:" << heap.getSize() << endl;
    cout << "Can the heap insert 1 again (0->false, 1->true):" << heap.insert(1) << endl;
    cout << endl;

    heap.insert(4);
    heap.insert(5);
    heap.insert(6);
    heap.insert(7);
    cout << "The Heap:";
    heap.display();
    cout << "Height:" << heap.getHeight() << endl;
    cout << "Size:" << heap.getSize() << endl;
    cout << endl;

    Heap<int> heap1;
    heap1.insert(7);
    heap1.insert(6);
    heap1.insert(5);
    heap1.insert(2);
    heap1.insert(3);
    heap1.insert(4);
    heap1.insert(1);
    heap1.display();

    return 0;
}