#include <iostream>
#include "Deque.h"
#include "Ivector.h"
#include "Stack.h"
#include "Tvector.h"
#include "Vector.h"

using namespace std;

int main() {
    cout << "[0/63] This is DQtest." << endl;
    cout << "Author: Weiqi Wang, 301417203." << endl;
    cout << endl;

    cout << "This test contains two parts.";
    cout << "In the first part, the program will store basic data structures into the deque,";
    cout << "includes int, float, string and pointers." << endl;
    cout << "In the second part, the program will store objects into the deque,";
    cout << "includes Deque, Vector, Stack, IVector and TVector." << endl;
    cout << "The program will test 63 examples in total." << endl;
    cout << endl;

    cout << "The program starts part 1." << endl;

    cout << "[1/63] The program starts initialize a deque with <int> type:" << endl;
    Deque<int> dequeInt;
    dequeInt.ddisplay();
    cout << endl;
    
    cout << "[2/63] The program enqueues 1 to the back of the deque:" << endl;
    dequeInt.enqueue(1);
    dequeInt.ddisplay();
    cout << endl;

    cout << "[3/63] The program clears the deque:" << endl;
    dequeInt.clear();
    dequeInt.ddisplay();
    cout << endl;

    cout << "[4/63] The program enqueues 2 to the back of the deque:" << endl;
    dequeInt.enqueue(2);
    dequeInt.ddisplay();
    cout << endl;

    cout << "[5/63] The program inserts 3 to the front of the deque:" << endl;
    dequeInt.jump(3);
    dequeInt.ddisplay();
    cout << endl;

    cout << "[6/63] The program removes the item at the back of the deque:" << endl;
    cout << "The number removed is: " << dequeInt.eject() << endl;
    dequeInt.ddisplay();
    cout << endl;

    cout << "[7/63] The program removes the item at the front of the deque:" << endl;
    cout << "The number removed is: " << dequeInt.dequeue() << endl;
    dequeInt.ddisplay();
    cout << endl;

    cout << "[8/63] The program enqueues 4 to the back of the deque:" << endl;
    dequeInt.enqueue(4);
    dequeInt.ddisplay();
    cout << endl;

    cout << "[9/63] The program inserts 5 to the front of the deque:" << endl;
    dequeInt.jump(5);
    dequeInt.ddisplay();
    cout << endl;

    cout << "[10/63] The program changes the size of the deque from 8 to 16:" << endl;
    dequeInt.reserve(16);
    for (int i = 10; i < 19; i++) {
        dequeInt.enqueue(i);
    }
    dequeInt.ddisplay();
    cout << endl;

    cout << "[11/63] The program changes the size of the deque from 16 to 1:" << endl;
    dequeInt.reserve(1);
    dequeInt.ddisplay();
    cout << endl;

    cout << "[12/63] The program clears the deque:" << endl;
    dequeInt.clear();
    dequeInt.ddisplay();
    cout << endl;

    cout << "[13/63] The program removes the item at the back of the deque:" << endl;
    cout << "The number removed is: " << dequeInt.dequeue() << endl;
    dequeInt.ddisplay();
    cout << "This test failed." << endl;
    cout << "The number removed is not a number in the deque," << endl;
    cout << "theSize changes to -1 and front changes to 1." << endl;
    cout << "However, the program still working." << endl;
    cout << endl;

    cout << "[14/63] The program clears the deque:" << endl;
    dequeInt.clear();
    dequeInt.ddisplay();
    cout << endl;

    cout << "[15/63] The program removes the item at the front of the deque:" << endl;
    cout << "The number removed is: " << dequeInt.eject() << endl;
    dequeInt.ddisplay();
    cout << endl;

    cout << "[16/63] The program adds 16 items at the back of the deque:" << endl;
    for(int i = 0; i < 16; i++) {
        dequeInt.enqueue(i);
    }
    dequeInt.ddisplay();
    cout << endl;

    cout << "[17/63] The program adds 16 items at the front of the deque:" << endl;
    for(int i = 16; i < 32; i++) {
        dequeInt.jump(i);
    }
    dequeInt.ddisplay();
    cout << endl;

    cout << "[18/63] The program removes 8 items from the back of the deque," << endl;
    cout << "        And the program enqueues each item into a new deque:" << endl;
    Deque<int> dequeIntTemp;
    for(int i = 0; i < 8; i++) {
        dequeIntTemp.enqueue(dequeInt.eject());
        dequeIntTemp.ddisplay();
    }
    cout << "The numbers removed are";
    dequeIntTemp.display();
    dequeInt.ddisplay();

    cout << "[19/63] The program removes 8 items from the front of the deque," << endl;
    cout << "        And the program enqueues each item into a new deque:" << endl;
    dequeIntTemp.clear();
    for(int i = 0; i < 8; i++) {
        dequeIntTemp.enqueue(dequeInt.dequeue());
    }
    cout << "The numbers removed are";
    dequeIntTemp.display();
    dequeInt.ddisplay();

    cout << "[20/63] The program adds 8 items at the back of the deque:" << endl;
    for(int i = 100; i < 108; i++) {
        dequeInt.enqueue(i);
    }
    dequeInt.ddisplay();
    cout << endl;

    cout << "[21/63] The program adds 8 items at the front of the deque:" << endl;
    for(int i = 108; i < 116; i++) {
        dequeInt.jump(i);
    }
    dequeInt.ddisplay();
    cout << endl;

    cout << "[22/63] The program starts initialize a deque with <double> type:" << endl;
    Deque<double> dequeDouble;
    dequeDouble.display();
    cout << endl;

    cout << "[23/63] The program enqueues 1.0 to the back of the deque:" << endl;
    dequeDouble.enqueue(1.0);
    dequeDouble.display();
    cout << endl;

    cout << "[24/63] The program inserts 1.1 to the front of the deque:" << endl;
    dequeDouble.jump(1.1);
    dequeDouble.display();
    cout << endl;    

    cout << "[25/63] The program removes the item at the back of the deque:" << endl;
    cout << "The number removed is: " << dequeDouble.eject() << endl;
    dequeDouble.display();
    cout << endl;

    cout << "[26/63] The program removes the item at the front of the deque:" << endl;
    cout << "The number removed is: " << dequeDouble.dequeue() << endl;
    dequeDouble.display();
    cout << endl;

    cout << "[27/63] The program starts initialize a deque with <string> type:" << endl;
    Deque<string> dequeString;

    cout << "[28/63] The program enqueues 'A' to the back of the deque:" << endl;
    dequeString.enqueue("A");
    dequeString.display();
    cout << endl;

    cout << "[29/63] The program inserts 'B' to the front of the deque:" << endl;
    dequeString.jump("B");
    dequeString.display();
    cout << endl;

    cout << "[30/63]The program starts initialize a deque with <*int> type." << endl;
    Deque<int*> dequeIntPtr;
    cout << endl;

    cout << "[31/63] The program adds 16 items at the back of the deque:" << endl;
    for(int i = 0; i < 16; i++) {
        int* j = new int(i);
        dequeIntPtr.enqueue(j);
    }
    dequeIntPtr.display();
    cout << endl;

    cout << "[32/63] The program inserts 16 items at the front of the deque:" << endl;
    for(int i = 0; i < 16; i++) {
        int* j = new int(i);
        dequeIntPtr.jump(j);
    }
    cout << "The deque is: [";
        for(int i = 0; i < dequeIntPtr.size(); i++) {
          cout << *dequeIntPtr[i];
          if(i != dequeIntPtr.size() - 1) {
            cout << ",";
          }
        }
        cout << "]" << endl;
    cout << endl;

    cout << "Part 1 has been finished. The program starts part 2." << endl;

    cout << "[33/63] It seems storing a deque<int> directly in deque has issues, ";
    cout << "due to the lack of key methods in Deque class." << endl;
    cout << "The program stores a deque<int>* in deque." << endl;
    Deque<Deque<int>*> dequeDequeInt;
    cout << endl;

    cout << "[34/63] The program enqueues 8 deque<int>* with 8 elements each in deque." << endl;
    Deque<int>* dequeIntTempPtr;
    for(int i = 0; i < 8; i++) {
        dequeIntTempPtr = new Deque<int>;
        for(int j = 0; j < 8; j++) {
            dequeIntTempPtr->enqueue(i*8+j);
        }
        dequeDequeInt.enqueue(dequeIntTempPtr);
    }
    for (int i = 0; i < dequeDequeInt.size(); i++) {
        cout << "The item " << i << " of the deque is ";
        dequeDequeInt[i]->display();
    }
    cout << endl;
    
    cout << "[35/63] The program jumps 8 deque<int>* with 8 elements each in deque." << endl;
    for(int i = 8; i < 16; i++) {
        dequeIntTempPtr = new Deque<int>;
        for(int j = 0; j < 8; j++) {
            dequeIntTempPtr->enqueue(i*8+j);
        }
        dequeDequeInt.jump(dequeIntTempPtr);
        // for (int k = 0; k < dequeDequeInt.size(); k++) {
        //     cout << "The item " << k << " of the deque is ";
        //     dequeDequeInt[k]->ddisplay();
        // }
        // dequeDequeInt.display();
        // cout << endl;
    }
    // dequeDequeInt.ddisplay();
    for (int i = 0; i < dequeDequeInt.size(); i++) {
        cout << "The item " << i << " of the deque is ";
        dequeDequeInt[i]->display();
    }
    cout << endl;

    cout << "[36/63] The program dequeues an element in deque." << endl;
    cout << "The deque removed is: ";
    dequeDequeInt.dequeue()->display();
    for (int i = 0; i < dequeDequeInt.size(); i++) {
        cout << "The item " << i << " of the deque is ";
        dequeDequeInt[i]->display();
    }
    cout << endl;

    cout << "[37/63] The program enqueues a deque<int>* with 8 elements each in deque." << endl;
    dequeIntTempPtr = new Deque<int>;
    for(int i = 1000; i < 1008; i++) {
        dequeIntTempPtr->enqueue(i);
    }
    dequeDequeInt.enqueue(dequeIntTempPtr);
    for (int i = 0; i < dequeDequeInt.size(); i++) {
        cout << "The item " << i << " of the deque is ";
        dequeDequeInt[i]->display();
    }
    cout << endl;

    cout << "[38/63] The program ejects an element in deque." << endl;
    cout << "The deque removed is: ";
    dequeDequeInt.eject()->display();
    for (int i = 0; i < dequeDequeInt.size(); i++) {
        cout << "The item " << i << " of the deque is ";
        dequeDequeInt[i]->display();
    }
    cout << endl;

    cout << "[39/63] The program stores a vector<int> in deque." << endl;
    Deque<Vector<int>> dequeVectorInt;
    cout << endl;

    cout << "[40/63] The program enqueues 4 vector<int> with 8 elements each in vector." << endl;
    for (int i = 0; i < 4; i++) {
        Vector<int> vectorIntTemp1;
        for (int j = 0; j < 8; j++) {
            vectorIntTemp1.push_back(i * 8 + j);
        }
        dequeVectorInt.enqueue(vectorIntTemp1);
    }
    for (int i = 0; i < dequeVectorInt.size(); i++) {
        cout << "The item " << i << " of the deque is [";
        for (int j = 0; j < dequeVectorInt[i].size(); j++) {
            cout << dequeVectorInt[i][j];
            if(j != dequeVectorInt[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    cout << endl;

    cout << "[41/63] The program jumps 4 vector<int> with 8 elements each in vector." << endl;
    for (int i = 4; i < 8; i++) {
        Vector<int> vectorIntTemp2;
        for (int j = 0; j < 8; j++) {
            vectorIntTemp2.push_back(i * 8 + j);
        }
        dequeVectorInt.jump(vectorIntTemp2);
    }
    for (int i = 0; i < dequeVectorInt.size(); i++) {
        cout << "The item " << i << " of the deque is [";
        for (int j = 0; j < dequeVectorInt[i].size(); j++) {
            cout << dequeVectorInt[i][j];
            if(j != dequeVectorInt[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    cout << endl;

    cout << "It seems the program can't store 8 vector<int> with 8 elements each in vector. " << endl;
    cout << endl;    

    cout << "[42/63] The program dequeues an element in deque." << endl;
    Vector<int> vectorIntTemp3;
    vectorIntTemp3 = dequeVectorInt.dequeue();
    cout << "The deque removed is: ";
    cout << "[";
    for (int i = 0; i < vectorIntTemp3.size(); i++) {
        cout << vectorIntTemp3[i];
        if(i != vectorIntTemp3.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    for (int i = 0; i < dequeVectorInt.size(); i++) {
        cout << "The item " << i << " of the deque is [";
        for (int j = 0; j < dequeVectorInt[i].size(); j++) {
            cout << dequeVectorInt[i][j];
            if(j != dequeVectorInt[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    cout << "Due to the lack of getFront() methods in Deque class, the DQarretytest file can only begins the loop at 0." << endl;
    cout << endl;

    cout << "[43/63] The program jumps a vector<int> with 8 elements each in vector." << endl;
    Vector<int> vectorIntTemp4;
    for (int i = 0; i < 8; i++) {
        vectorIntTemp4.push_back(i);
    }
    dequeVectorInt.jump(vectorIntTemp4);
    for (int i = 0; i < dequeVectorInt.size(); i++) {
        cout << "The item " << i << " of the deque is [";
        for (int j = 0; j < dequeVectorInt[i].size(); j++) {
            cout << dequeVectorInt[i][j];
            if(j != dequeVectorInt[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    cout << endl;

    cout << "[44/63] The program ejects an element in deque." << endl;
    Vector<int> vectorIntTemp5;
    vectorIntTemp5 = dequeVectorInt.eject();
    cout << "The deque removed is: ";
    cout << "[";
    for (int i = 0; i < vectorIntTemp5.size(); i++) {
        cout << vectorIntTemp5[i];
        if(i != vectorIntTemp5.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    for (int i = 0; i < dequeVectorInt.size(); i++) {
        cout << "The item " << i << " of the deque is [";
        for (int j = 0; j < dequeVectorInt[i].size(); j++) {
            cout << dequeVectorInt[i][j];
            if(j != dequeVectorInt[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    cout << endl;

    cout << "[45/63] The program enqueues a vector<int> with 8 elements each in vector." << endl;
    Vector<int> vectorIntTemp6;
    for (int i = 0; i < 8; i++) {
        vectorIntTemp6.push_back(i);
    }
    dequeVectorInt.enqueue(vectorIntTemp6);
    for (int i = 0; i < dequeVectorInt.size(); i++) {
        cout << "The item " << i << " of the deque is [";
        for (int j = 0; j < dequeVectorInt[i].size(); j++) {
            cout << dequeVectorInt[i][j];
            if(j != dequeVectorInt[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    cout << endl;

    cout << "[46/63] The program can't store a tvector directly in deque. " << endl;
    cout << "The program stores a tvector<int>* in deque." << endl;
    Deque<TVector<int>*> dequeTVectorInt;
    cout << endl;

    cout << "[47/63] The program enqueues 8 tvector<int>* with 8 elements each in tvector." << endl;
    TVector<int>* tvectorIntTempPtr;
    for (int i = 0; i < 8; i++) {
        tvectorIntTempPtr = new TVector<int>;
        for (int j = 0; j < 8; j++) {
            tvectorIntTempPtr->push_back(i * 8 + j);
        }
        dequeTVectorInt.enqueue(tvectorIntTempPtr);
    }
    for (int i = 0; i < dequeTVectorInt.size(); i++) {
        cout << "The item " << i << " of the deque is:" << endl;
        dequeTVectorInt[i]->display();
    }
    cout << endl;

    cout << "[48/63] The program jumps 8 tvector<int>* with 8 elements each in tvector." << endl;
    for (int i = 8; i < 16; i++) {
        tvectorIntTempPtr = new TVector<int>;
        for (int j = 0; j < 8; j++) {
            tvectorIntTempPtr->push_back(i * 8 + j);
        }
        dequeTVectorInt.jump(tvectorIntTempPtr);
    }
    for (int i = 0; i < dequeTVectorInt.size(); i++) {
        cout << "The iitem " << i << " of the deque is:" << endl;
        dequeTVectorInt[i]->display();
    }
    cout << endl;

    cout << "[49/63] The program dequeues an element in deque." << endl;
    cout << "The deque removed is:" << endl;
    dequeTVectorInt.dequeue()->display();
    for (int i = 0; i < dequeTVectorInt.size(); i++) {
        cout << "The item " << i << " of the deque is:" << endl;
        dequeTVectorInt[i]->display();
    }
    cout << endl;

    cout << "[50/63] The program enqueues a tvector<int>* with 8 elements each in tvector." << endl;
    tvectorIntTempPtr = new TVector<int>;
    for(int i = 1000; i < 1008; i++) {
        tvectorIntTempPtr->push_back(i);
    }
    dequeTVectorInt.enqueue(tvectorIntTempPtr);
    for (int i = 0; i < dequeTVectorInt.size(); i++) {
        cout << "The item " << i << " of the deque is:" << endl;
        dequeTVectorInt[i]->display();
    }
    cout << endl;

    cout << "[51/63] The program ejects an element in deque." << endl;
    cout << "The deque removed is:" << endl;
    dequeTVectorInt.eject();
    for (int i = 0; i < dequeTVectorInt.size(); i++) {
        cout << "The item " << i << " of the deque is:" << endl;
        dequeTVectorInt[i]->display();
    }
    cout << endl;

    cout << "[52/63] The program can't store a stack directly in deque. " << endl;
    cout << "The program stores a stack<int>* in deque." << endl;
    Deque<Stack<int>*> dequeStackInt;
    cout << endl;

    cout << "[53/63] The program enqueues 8 stack<int>* with 8 elements each in stack." << endl;
    Stack<int>* stackIntTempPtr;
    for (int i = 0; i < 8; i++) {
        stackIntTempPtr = new Stack<int>;
        for (int j = 0; j < 8; j++) {
            stackIntTempPtr->push(i * 8 + j);
        }
        dequeStackInt.enqueue(stackIntTempPtr);
    }
    for (int i = 0; i < dequeStackInt.size(); i++) {
        cout << "The item " << i << " of the deque is:" << endl;
        dequeStackInt[i]->display();
    }
    cout << endl;

    cout << "[54/63] The program jumps 8 stack<int>* with 8 elements each in stack." << endl;
    for (int i = 8; i < 16; i++) {
        stackIntTempPtr = new Stack<int>;
        for (int j = 0; j < 8; j++) {
            stackIntTempPtr->push(i * 8 + j);
        }
        dequeStackInt.jump(stackIntTempPtr);
    }
    for (int i = 0; i < dequeStackInt.size(); i++) {
        cout << "The iitem " << i << " of the deque is:" << endl;
        dequeStackInt[i]->display();
    }
    cout << endl;

    cout << "[55/63] The program dequeues an element in deque." << endl;
    cout << "The deque removed is:" << endl;
    dequeStackInt.dequeue()->display();
    for (int i = 0; i < dequeStackInt.size(); i++) {
        cout << "The item " << i << " of the deque is:" << endl;
        dequeStackInt[i]->display();
    }
    cout << endl;

    cout << "[56/63] The program enqueues a stack<int>* with 8 elements each in stack." << endl;
    stackIntTempPtr = new Stack<int>;
    for(int i = 1000; i < 1008; i++) {
        stackIntTempPtr->push(i);
    }
    dequeStackInt.enqueue(stackIntTempPtr);
    for (int i = 0; i < dequeStackInt.size(); i++) {
        cout << "The item " << i << " of the deque is:" << endl;
        dequeStackInt[i]->display();
    }
    cout << endl;

    cout << "[57/63] The program ejects an element in deque." << endl;
    cout << "The deque removed is:" << endl;
    dequeStackInt.eject()->display();
    for (int i = 0; i < dequeStackInt.size(); i++) {
        cout << "The item " << i << " of the deque is:" << endl;
        dequeStackInt[i]->display();
    }
    cout << endl;

    cout << "[58/63] The program can't store a IVector directly in deque. " << endl;
    cout << "The program stores a IVector* in deque." << endl;
    Deque<IVector*> dequeIVector;
    cout << endl;

    cout << "[59/63] The program enqueues 8 IVector with 8 elements each in IVector." << endl;
    IVector* IVectorTempPtr;
    for (int i = 0; i < 8; i++) {
        IVectorTempPtr = new IVector;
        for (int j = 0; j < 8; j++) {
            IVectorTempPtr->push_back(i * 8 + j);
        }
        dequeIVector.enqueue(IVectorTempPtr);
    }
    for (int i = 0; i < dequeIVector.size(); i++) {
        cout << "The item " << i << " of the deque is:" << endl;
        dequeIVector[i]->display();
    }
    cout << endl;

    cout << "[60/63] The program jumps 8 IVector with 8 elements each in IVector." << endl;
    for (int i = 8; i < 16; i++) {
        IVectorTempPtr = new IVector;
        for (int j = 0; j < 8; j++) {
            IVectorTempPtr->push_back(i * 8 + j);
        }
        dequeIVector.jump(IVectorTempPtr);
    }
    for (int i = 0; i < dequeIVector.size(); i++) {
        cout << "The iitem " << i << " of the deque is:" << endl;
        dequeIVector[i]->display();
    }
    cout << endl;

    cout << "[61/63] The program dequeues an element in deque." << endl;
    cout << "The deque removed is:" << endl;
    dequeIVector.dequeue()->display();
    for (int i = 0; i < dequeIVector.size(); i++) {
        cout << "The item " << i << " of the deque is:" << endl;
        dequeIVector[i]->display();
    }
    cout << endl;

    cout << "[62/63] The program enqueues a IVector with 8 elements each in IVector." << endl;
    IVectorTempPtr = new IVector;
    for(int i = 1000; i < 1008; i++) {
        IVectorTempPtr->push_back(i);
    }
    dequeIVector.enqueue(IVectorTempPtr);
    for (int i = 0; i < dequeIVector.size(); i++) {
        cout << "The item " << i << " of the deque is:" << endl;
        dequeIVector[i]->display();
    }
    cout << endl;

    cout << "[63/63] The program ejects an element in deque." << endl;
    cout << "The deque removed is:" << endl;
    dequeIVector.eject()->display();
    for (int i = 0; i < dequeIVector.size(); i++) {
        cout << "The item " << i << " of the deque is:" << endl;
        dequeIVector[i]->display();
    }
    cout << endl;

    cout << "DQtest finished." << endl;

    return 0;
}