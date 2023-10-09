#include <iostream>

const int x_ = 157;

int findMaxRecursive(int* arr, int size, int max);
int findMinRecursive(int* arr, int size, int min);


int main() {

	int arr[x_];

	for (int i = 0; i < x_; i++) {
		arr[i] = i;
	}

	int number = 0;

	std::cout << "max value in the array: " << findMaxRecursive(arr, x_, arr[0]) << std::endl;
	std::cout << "min value in the array: " << findMinRecursive(arr, x_, arr[0]) << std::endl;

}

int findMaxRecursive(int* arr, int size, int max) {
	if (size == 0) {
		return max;
	}
	else if (*arr > max) {
		max = *arr;
	}

	findMaxRecursive(++arr, size - 1, max);
}

int findMinRecursive(int* arr, int size, int min) {
	if (size == 0) {
		return min;
	}
	else if (*arr < min) {
		min = *arr;
	}

	findMinRecursive(++arr, size - 1, min);
}