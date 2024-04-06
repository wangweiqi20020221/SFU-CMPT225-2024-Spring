#pragma once

#include <iostream>

template <class type>
void quick_sort_original(type& arrey, const int left, const int right) {
	if (left >= right) {
		return;
	}
	int temp_left = left;
	int temp_right = right;
	// Set standard
	type standard = arrey[left];
	temp_left++;
	// Set left and right
	while (temp_left < temp_right && arrey[temp_left] < standard) {
		temp_left++;
	}
	while (temp_left < temp_right && arrey[temp_right] > standard) {
		temp_right--;
	}
	// Swap
	type temp = arrey[temp_left];
	arrey[temp_left] = arrey[temp_right];
	arrey[temp_right] = temp;
	for (int index = left; index < temp_left; index++) {
		arrey[index] = arrey[index + 1];
	}
	arrey[temp_left] = standard;
	quick_sort_original(arrey, left, temp_left);
	quick_sort_original(arrey, temp_left + 1, right);
};