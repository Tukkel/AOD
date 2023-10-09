#include <iostream>
#include <stdlib.h>
#include <vector>

#define SIZE 100

void selection_sort(int* arr, int size);

int main()
{
	srand(time(NULL));

	int arr[SIZE] = { 0 };

	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 70;
	}

	for (int i = 0; i < SIZE; i++) {
		std::cout << arr[i] << std::endl;
	}

	selection_sort(arr, SIZE);

	std::cout << "Sorted array:" << std::endl;

	for (int i = 0; i < SIZE; i++) {
		std::cout << arr[i] << std::endl;
	}
}

void selection_sort(int* arr, int size)
{
	if (size <= 0) return;

	for (int i = 0; i < size; i++) {
		int min_temp = arr[i];
		int min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < min_temp) {
				min_temp = arr[j];
				min_index = j;
			}
		}
		arr[min_index] = arr[i];
		arr[i] = min_temp;
	}
}