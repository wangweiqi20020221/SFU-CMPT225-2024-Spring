#include <iostream>

#include "IPQ.h"

using namespace std;

int main() {
    cout << "[13/0] Assignment 3, SFU CMPT 225" << endl;
    cout << "Author: Weiqi Wang" << endl;
    cout << "ID: 301417203" << endl;

    cout << "[13/1] The program initializes a heap." << endl;
    Heap<int> heap;
    cout << endl;

    cout << "[13/2] The program inserts 1 to the heap." << endl;
    heap.insert(1);
    cout << "The Heap:";
    heap.display();
    cout << "Height:" << heap.getHeight() << endl;
    cout << "Size:" << heap.getSize() << endl;
    cout << endl;

    cout << "[13/3] The program inserts 2 and 3 to the heap." << endl;
    heap.insert(2);
    heap.insert(3);
    cout << "The Heap:";
    heap.display();
    cout << "Height:" << heap.getHeight() << endl;
    cout << "Size:" << heap.getSize() << endl;
    cout << "Can the heap insert 1 again (0->false, 1->true):" << heap.insert(1) << endl;
    cout << endl;

    cout << "[13/4] The program inserts 4, 5, 6 and 7 to the heap." << endl;
    heap.insert(4);
    heap.insert(5);
    heap.insert(6);
    heap.insert(7);
    cout << "The Heap:";
    heap.display();
    cout << "Height:" << heap.getHeight() << endl;
    cout << "Size:" << heap.getSize() << endl;
    cout << endl;

    cout << "[13/5] The program removes 1 from the heap." << endl;
    heap.remove(1);
    cout << "The Heap:";
    heap.display();
    cout << "Height:" << heap.getHeight() << endl;
    cout << "Size:" << heap.getSize() << endl;
    cout << endl;

    cout << "[13/6] The program clears the heap." << endl;
    heap.clear();
    cout << "The Heap:";
    heap.display();
    cout << "Height:" << heap.getHeight() << endl;
    cout << "Size:" << heap.getSize() << endl;
    cout << endl;

    cout << "[13/7] The program inserts 7 numbers randomly to the heap." << endl;
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

    cout << "[13/8] The program initializes an IPQ." << endl;
    IPQ ipq;
    cout << "Is IPQ Empty (0 false, 1 true):" << ipq.isEmpty() << endl;
    cout << endl;

    cout << "[13/9] The program inserts 7 items to IPQ." << endl;
    ipq.insert("CMPT102", 7);
    ipq.insert("CMPT105", 6);
    ipq.insert("CMPT106", 5);
    ipq.insert("CMPT110", 2);
    ipq.insert("CMPT115", 3);
    ipq.insert("CMPT120", 4);
    ipq.insert("CMPT125", 1);
    cout << endl;

    cout << "[13/10] The program updates CMPT125 to priority 8." << endl;
    cout << "Before update, the smallest item is:" << ipq.getMin() << endl;
    ipq.updatePriority("CMPT125", 8);
    cout << "After update, the smallest item is:" << ipq.getMin() << endl;
    cout << endl;

    cout << "[13/11] The program removes the smallest task." << endl;
    ipq.deleteMin();
    cout << "After update, the smallest item is:" << ipq.getMin() << endl;
    cout << endl;

    cout << "[13/12] The program clears the IPQ." << endl;
    ipq.clear();
    cout << endl;

    cout << "[13/13] The program initializes an IPQ by taskIDs and priorities." << endl;
    vector<string> taskIDs;
    taskIDs.push_back("CMPT102");
    taskIDs.push_back("CMPT105");
    taskIDs.push_back("CMPT106");
    taskIDs.push_back("CMPT110");
    taskIDs.push_back("CMPT115");
    taskIDs.push_back("CMPT120");
    taskIDs.push_back("CMPT125");
    vector<int> priorities;
    priorities.push_back(7);
    priorities.push_back(6);
    priorities.push_back(5);
    priorities.push_back(2);
    priorities.push_back(3);
    priorities.push_back(4);
    priorities.push_back(1);
    IPQ ipq1(taskIDs, priorities);
    cout << "The smallest item is:" << ipq1.getMin() << endl;
    cout << endl;

    cout << "Tests finishes.";

    return 0;
}