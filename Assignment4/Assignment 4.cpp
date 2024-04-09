// Assignment 4.cpp: 定义应用程序的入口点。
//

#include "Assignment 4.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int *arrey = new int[100000];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100000; i++) {
		arrey[i] = rand();
	}

	int *arrey1 = new int[100000];
	for (int i = 0; i < 100000; i++) {
		arrey1[i] = arrey[i];
	}

    clock_t startTime, endTime;
    startTime = clock();
	sort(arrey1, arrey1 + 100000);
    endTime = clock();
    cout << "Time use for std::sort(): " << endTime - startTime << endl;
	delete[] arrey1;

    int *arrey2 = new int[100000];
    for (int i = 0; i < 100000; i++) {
        arrey2[i] = arrey[i];
    }
    startTime = clock();
    quick_sort_original(arrey2, 0, 99999);
    endTime = clock();
    cout << "Time use for original quick sort: " << endTime - startTime << endl;
    delete[] arrey2;

    int *arrey3 = new int[100000];
    for (int i = 0; i < 100000; i++) {
        arrey3[i] = arrey[i];
    }
    startTime = clock();
    quick_sort_standard_optimization(arrey3, 0, 99999);
    endTime = clock();
    cout << "Time use for std::sort(): " << endTime - startTime << endl;
    delete[] arrey3;

	delete[] arrey;
	return 0;
}
