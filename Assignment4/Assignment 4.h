#pragma once

#include <iostream>

void quick_sort_lofi(int arrey[], const int left, const int right) {
    if (left >= right) {
        return;
    }
    int temp_left = left;
    int temp_right = left + 1;
    // Set standard
    int standard = arrey[left];
    // Set left and right
    while(temp_left < right) {
        if (arrey[temp_right] < standard) {
            // Swap
            int temp = arrey[temp_left];
            arrey[temp_left] = arrey[temp_right];
            arrey[temp_right] = temp;
            temp_left++;
        }

        temp_right++;
    }
    int temp = arrey[left];
    arrey[left] = arrey[temp_left];
    arrey[temp_left] = temp;
    quick_sort_lofi(arrey, left, temp_left - 1);
    quick_sort_lofi(arrey, temp_left + 1, right);
};

void quick_sort_original(int arrey[], const int left, const int right) {
	if (left >= right) {
		return;
	}
	int temp_left = left;
	int temp_right = right;
	// Set standard
	int standard = arrey[left];
	// Set left and right
    while(temp_left < temp_right) {
        while (temp_left < temp_right && arrey[temp_right] >= standard) {
            temp_right--;
        }
        while (temp_left < temp_right && arrey[temp_left] <= standard) {
            temp_left++;
        }
        // Swap
        int temp = arrey[temp_left];
        arrey[temp_left] = arrey[temp_right];
        arrey[temp_right] = temp;
    }
    int temp = arrey[left];
    arrey[left] = arrey[temp_left];
    arrey[temp_left] = temp;
	quick_sort_original(arrey, left, temp_left - 1);
	quick_sort_original(arrey, temp_left + 1, right);
};

void quick_sort_standard_optimization(int arrey[], const int left, const int right) {
    if (left >= right) {
        return;
    }
    int temp_left = left;
    int temp_right = right;
    // Set standard
    if ((arrey[left] <= arrey[(left+right)/2] && arrey[(left+right)/2] <= arrey[right]) || (arrey[right] <= arrey[(left+right)/2] && arrey[(left+right)/2] <= arrey[left])) {
        int temp = arrey[left];
        arrey[left] = arrey[(left+right)/2];
        arrey[(left+right)/2] = temp;
    } else if ((arrey[(left+right)/2] <= arrey[left] && arrey[left] <= arrey[right]) || (arrey[right] <= arrey[left] && arrey[left] <= arrey[(left+right)/2])) {

    } else {
        int temp = arrey[left];
        arrey[left] = arrey[right];
        arrey[right] = temp;
    }
    int standard = arrey[left];
    // Set left and right
    while(temp_left < temp_right) {
        while (temp_left < temp_right && arrey[temp_right] >= standard) {
            temp_right--;
        }
        while (temp_left < temp_right && arrey[temp_left] <= standard) {
            temp_left++;
        }
        // Swap
        int temp = arrey[temp_left];
        arrey[temp_left] = arrey[temp_right];
        arrey[temp_right] = temp;
    }
    int temp = arrey[left];
    arrey[left] = arrey[temp_left];
    arrey[temp_left] = temp;
    quick_sort_standard_optimization(arrey, left, temp_left - 1);
    quick_sort_standard_optimization(arrey, temp_left + 1, right);
};
