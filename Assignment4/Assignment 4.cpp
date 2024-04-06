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
	sort(arrey1, arrey1 + 100000);

	delete[] arrey1;
	delete[] arrey;
	return 0;
}
