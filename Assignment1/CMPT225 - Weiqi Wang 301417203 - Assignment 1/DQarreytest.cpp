#include <iostream>
#include "Deque.h"

using namespace std;

int main() {
    cout << "[0/3] This is DQarreytest." << endl;
    cout << "Author: Weiqi Wang, 301417203." << endl;
    cout << endl;

    cout << "[1/3] The program initializes a deque<int>." << endl;
    Deque<int> dequeInt;
    for(int i = 0; i < 8; i++) {
        dequeInt.enqueue(i);
    }
    cout << "The deque is:";
    dequeInt.display();

    cout << "[2/3] The program starts testing '[]':" << endl;
    cout << "DequeInt[0] is " << dequeInt[0] << endl;
    cout << endl;

    cout << "[3/3] The program changes item 0 of the deque by using '[]':" << endl;
    dequeInt[0] = -1;
    dequeInt.display();

    cout << "DQarreytest finished." << endl;

    return 0;
}