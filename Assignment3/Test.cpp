#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
    cout << "[1] The program initialize a heap." << endl;
    Heap<int> heap;
    cout << endl;

    cout << "[2] The program insert 1 to the heap." << endl;
    heap.insert(1);
    cout << "The Heap:";
    heap.display();
    cout << "Height:" << heap.getHeight() << endl;
    cout << "Size:" << heap.getSize() << endl;
    cout << endl;

    cout << "[3] The program insert 2 and 3 to the heap." << endl;
    heap.insert(2);
    heap.insert(3);
    cout << "The Heap:";
    heap.display();
    cout << "Height:" << heap.getHeight() << endl;
    cout << "Size:" << heap.getSize() << endl;
    cout << "Can the heap insert 1 again (0->false, 1->true):" << heap.insert(1) << endl;
    cout << endl;

    cout << "[4] The program insert 4, 5, 6 and 7 to the heap." << endl;
    heap.insert(4);
    heap.insert(5);
    heap.insert(6);
    heap.insert(7);
    cout << "The Heap:";
    heap.display();
    cout << "Height:" << heap.getHeight() << endl;
    cout << "Size:" << heap.getSize() << endl;
    cout << endl;

    cout << "[5] The program remove 1 from the heap." << endl;
    heap.remove(1);
    cout << "The Heap:";
    heap.display();
    cout << "Height:" << heap.getHeight() << endl;
    cout << "Size:" << heap.getSize() << endl;
    cout << endl;

    cout << "[6] The program clear the heap." << endl;
    heap.clear();
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