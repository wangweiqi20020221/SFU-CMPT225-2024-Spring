#include <iostream>
#include <time.h>
#include <cstdlib>

#include "OSLL.h"
#include "OSULL.h"

using namespace std;

clock_t osllInsertTest(int size) {
    OSLL<int> osll;
    clock_t startTime, endTime;
    startTime = clock();
    for(int num = 1; num <= size; num++) {
        osll.insert(num);
    }
    endTime = clock();
    return endTime - startTime;
}

clock_t osllInsertTest2(int size) {
    OSLL<int> osll;
    clock_t startTime, endTime;
    startTime = clock();
    for(int num = size; num > 0; num--) {
        osll.insert(num);
    }
    endTime = clock();
    return endTime - startTime;
}

clock_t osllInsertTest3(int size) {
    OSLL<int> osll;
    clock_t startTime, endTime;
    srand((unsigned)time(NULL));
    startTime = clock();
    for(int i = 0; i < size; i++) {
        osll.insert(rand());
    }
    endTime = clock();
    return endTime - startTime;
}

clock_t osllRemoveTest(int size) {
    OSLL<int> osll;
    clock_t startTime, endTime;
    
    for(int num = 1; num <= size; num++) {
        osll.insert(num);
    }

    startTime = clock();
    for(int i = 0; i < size; i++) {
        osll.remove(osll.getMax());
    }
    endTime = clock();
    return endTime - startTime;
}

clock_t osllRemoveTest2(int size) {
    OSLL<int> osll;
    clock_t startTime, endTime;
    
    for(int num = 1; num <= size; num++) {
        osll.insert(num);
    }

    startTime = clock();
    for(int i = 0; i < size; i++) {
        osll.remove(osll.getMin());
    }
    endTime = clock();
    return endTime - startTime;
}

clock_t osllRemoveTest3(int size) {
    OSLL<int> osll;
    clock_t startTime, endTime;
    srand((unsigned)time(NULL));
    for(int num = 1; num <= 500000; num++) {
        osll.insert(num);
    }

    startTime = clock();
    for(int i = 0; i < size; i++) {
        osll.remove(rand());
    }
    endTime = clock();
    return endTime - startTime;
}

clock_t osllSearchTest(int size) {
    OSLL<int> osll;
    clock_t startTime, endTime;
    srand((unsigned)time(NULL));
    for(int num = 1; num <= 500000; num++) {
        osll.insert(num);
    }

    startTime = clock();
    for(int i = 0; i < size; i++) {
        osll.find(rand());
    }
    endTime = clock();
    return endTime - startTime;
}

clock_t osullInsertTest(int size) {
    OSULL<int> osull;
    clock_t startTime, endTime;
    startTime = clock();
    for(int num = 1; num <= size; num++) {
        osull.insert(num);
    }
    endTime = clock();
    return endTime - startTime;
}

clock_t osullInsertTest2(int size) {
    OSULL<int> osull;
    clock_t startTime, endTime;
    startTime = clock();
    for(int num = size; num > 0; num--) {
        osull.insert(num);
    }
    endTime = clock();
    return endTime - startTime;
}

clock_t osullInsertTest3(int size) {
    OSULL<int> osull;
    clock_t startTime, endTime;
    srand((unsigned)time(NULL));
    startTime = clock();
    for(int i = 0; i < size; i++) {
        osull.insert(rand());
    }
    endTime = clock();
    return endTime - startTime;
}

clock_t osullRemoveTest(int size) {
    OSULL<int> osull;
    clock_t startTime, endTime;
    
    for(int num = 1; num <= size; num++) {
        osull.insert(num);
    }
    
    startTime = clock();
    for(int i = 0; i < size; i++) {
        osull.remove(osull.getMax());
    }
    endTime = clock();
    return endTime - startTime;
}

clock_t osullRemoveTest2(int size) {
    OSULL<int> osull;
    clock_t startTime, endTime;
    
    for(int num = 1; num <= size; num++) {
        osull.insert(num);
    }
    
    startTime = clock();
    for(int i = 0; i < size; i++) {
        osull.remove(osull.getMin());
    }
    endTime = clock();
    return endTime - startTime;
}

clock_t osullRemoveTest3(int size) {
    OSULL<int> osull;
    clock_t startTime, endTime;
    srand((unsigned)time(NULL));
    for(int num = 1; num <= 500000; num++) {
        osull.insert(num);
    }
    startTime = clock();
    for(int i = 0; i < size; i++) {
        osull.remove(rand());
    }
    endTime = clock();
    return endTime - startTime;
}

clock_t osullSearchTest(int size) {
    OSULL<int> osull;
    clock_t startTime, endTime;
    srand((unsigned)time(NULL));
    for(int num = 1; num <= 500000; num++) {
        osull.insert(num);
    }
    startTime = clock();
    for(int i = 0; i < size; i++) {
        osull.find(rand());
    }
    endTime = clock();
    return endTime - startTime;
}

int main() {
    cout << "Data inserting test." << endl;

    cout << "Inserting increasing numbers into osll." << endl;
    cout << "Size: 10, Totle Time : " << osllInsertTest(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osllInsertTest(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osllInsertTest(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osllInsertTest(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osllInsertTest(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osllInsertTest(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osllInsertTest(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osllInsertTest(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osllInsertTest(500000) << " clocks" << endl;

    cout << "Inserting increasing numbers into osull." << endl;
    cout << "Size: 10, Totle Time : " << osullInsertTest(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osullInsertTest(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osullInsertTest(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osullInsertTest(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osullInsertTest(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osullInsertTest(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osullInsertTest(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osullInsertTest(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osullInsertTest(500000) << " clocks" << endl;

    cout << "Inserting decreasing numbers into osll." << endl;
    cout << "Size: 10, Totle Time : " << osllInsertTest2(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osllInsertTest2(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osllInsertTest2(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osllInsertTest2(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osllInsertTest2(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osllInsertTest2(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osllInsertTest2(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osllInsertTest2(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osllInsertTest2(500000) << " clocks" << endl;

    cout << "Inserting decreasing numbers into osull." << endl;
    cout << "Size: 10, Totle Time : " << osullInsertTest2(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osullInsertTest2(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osullInsertTest2(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osullInsertTest2(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osullInsertTest2(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osullInsertTest2(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osullInsertTest2(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osullInsertTest2(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osullInsertTest2(500000) << " clocks" << endl;

    cout << "Removing increasing numbers from osll." << endl;
    cout << "Size: 10, Totle Time : " << osllRemoveTest2(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osllRemoveTest2(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osllRemoveTest2(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osllRemoveTest2(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osllRemoveTest2(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osllRemoveTest2(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osllRemoveTest2(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osllRemoveTest2(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osllRemoveTest2(500000) << " clocks" << endl;

    cout << "Removing increasing numbers from osull." << endl;
    cout << "Size: 10, Totle Time : " << osullRemoveTest2(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osullRemoveTest2(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osullRemoveTest2(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osullRemoveTest2(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osullRemoveTest2(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osullRemoveTest2(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osullRemoveTest2(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osullRemoveTest2(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osullRemoveTest2(500000) << " clocks" << endl;

    cout << "Removing decreasing numbers from osll." << endl;
    cout << "Size: 10, Totle Time : " << osllRemoveTest(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osllRemoveTest(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osllRemoveTest(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osllRemoveTest(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osllRemoveTest(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osllRemoveTest(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osllRemoveTest(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osllRemoveTest(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osllRemoveTest(500000) << " clocks" << endl;

    cout << "Removing decreasing numbers from osull." << endl;
    cout << "Size: 10, Totle Time : " << osullRemoveTest(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osullRemoveTest(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osullRemoveTest(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osullRemoveTest(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osullRemoveTest(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osullRemoveTest(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osullRemoveTest(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osullRemoveTest(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osullRemoveTest(500000) << " clocks" << endl;

    cout << "Inserting random numbers into osll." << endl;
    cout << "Size: 10, Totle Time : " << osllInsertTest3(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osllInsertTest3(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osllInsertTest3(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osllInsertTest3(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osllInsertTest3(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osllInsertTest3(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osllInsertTest3(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osllInsertTest3(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osllInsertTest3(500000) << " clocks" << endl;

    cout << "Inserting random numbers into osull." << endl;
    cout << "Size: 10, Totle Time : " << osullInsertTest3(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osullInsertTest3(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osullInsertTest3(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osullInsertTest3(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osullInsertTest3(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osullInsertTest3(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osullInsertTest3(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osullInsertTest3(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osullInsertTest3(500000) << " clocks" << endl;

    cout << "Removing random numbers from a osll of 500000 int numbers." << endl;
    cout << "Size: 10, Totle Time : " << osllRemoveTest3(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osllRemoveTest3(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osllRemoveTest3(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osllRemoveTest3(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osllRemoveTest3(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osllRemoveTest3(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osllRemoveTest3(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osllRemoveTest3(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osllRemoveTest3(500000) << " clocks" << endl;

    cout << "Removing random numbers from a osull of 500000 int numbers." << endl;
    cout << "Size: 10, Totle Time : " << osullRemoveTest3(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osullRemoveTest3(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osullRemoveTest3(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osullRemoveTest3(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osullRemoveTest3(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osullRemoveTest3(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osullRemoveTest3(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osullRemoveTest3(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osullRemoveTest3(500000) << " clocks" << endl;

    cout << "Finding random numbers from a osll of 500000 int numbers." << endl;
    cout << "Size: 10, Totle Time : " << osllSearchTest(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osllSearchTest(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osllSearchTest(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osllSearchTest(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osllSearchTest(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osllSearchTest(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osllSearchTest(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osllSearchTest(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osllSearchTest(500000) << " clocks" << endl;

    cout << "Finding random numbers from a osull of 500000 int numbers." << endl;
    cout << "Size: 10, Totle Time : " << osullSearchTest(10) << " clocks" << endl;
    cout << "Size: 100, Totle Time : " << osullSearchTest(100) << " clocks" << endl;
    cout << "Size: 1000, Totle Time : " << osullSearchTest(1000) << " clocks" << endl;
    cout << "Size: 10000, Totle Time : " << osullSearchTest(10000) << " clocks" << endl;
    cout << "Size: 100000, Totle Time : " << osullSearchTest(100000) << " clocks" << endl;
    cout << "Size: 200000, Totle Time : " << osullSearchTest(200000) << " clocks" << endl;
    cout << "Size: 300000, Totle Time : " << osullSearchTest(300000) << " clocks" << endl;
    cout << "Size: 400000, Totle Time : " << osullSearchTest(400000) << " clocks" << endl;
    cout << "Size: 500000, Totle Time : " << osullSearchTest(500000) << " clocks" << endl;

    return 0;
}