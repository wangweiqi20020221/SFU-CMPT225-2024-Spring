#include <iostream>

#include "IPQ.h"

using namespace std;

int main() {
    cout << "[0] Assignment 3, SFU CMPT 225" << endl;
    cout << "Author: Weiqi Wang" << endl;
    cout << "ID: 301417203" << endl;

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

    cout << "[7] The program insert 7 numbers randomly to the heap." << endl;
    Heap<int> heap1;
    heap1.insert(7);
    heap1.insert(6);
    heap1.insert(5);
    heap1.insert(2);
    heap1.insert(3);
    heap1.insert(4);
    heap1.insert(1);
    cout << "The Heap:";
    heap1.display();
    cout << "Height:" << heap.getHeight() << endl;
    cout << "Size:" << heap.getSize() << endl;
    cout << endl;

    cout << "[8] The program initialize an IPQ." << endl;
    IPQ ipq;
    cout << "Is IPQ Empty (0 false, 1 true):" << ipq.isEmpty() << endl;
    cout << endl;

    cout << "[9] The program insert 7 items to IPQ." << endl;
    ipq.insert("CMPT102", 7);
    ipq.insert("CMPT105", 6);
    ipq.insert("CMPT106", 5);
    ipq.insert("CMPT110", 2);
    ipq.insert("CMPT115", 3);
    ipq.insert("CMPT120", 4);
    ipq.insert("CMPT125", 1);
    cout << endl;

    cout << "[10] The program update CMPT125 to priority 8" << endl;
    cout << "Before update, the smallest item is:" << ipq.getMin() << endl;
    ipq.updatePriority("CMPT125", 8);
    cout << "After update, the smallest item is:" << ipq.getMin() << endl;
    cout << endl;

    return 0;
}