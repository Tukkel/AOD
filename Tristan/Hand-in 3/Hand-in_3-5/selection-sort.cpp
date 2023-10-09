#include <iostream>
#include <stdlib.h>
#include <vector>

#define SIZE 100

void selection_sort(int* arr, int size);

template <typename Comparable>
void selection_sort_template(std::vector<Comparable>* vec_ptr);

int main()
{
	srand(time(NULL));

	//int arr[SIZE] = { 0 };

	//for (int i = 0; i < SIZE; i++) {
	//	arr[i] = rand() % 70;
	//}

	//for (int i = 0; i < SIZE; i++) {
	//	std::cout << arr[i] << std::endl;
	//}

	//selection_sort(arr, SIZE);

	//std::cout << "Sorted array:" << std::endl;

	//for (int i = 0; i < SIZE; i++) {
	//	std::cout << arr[i] << std::endl;
	//}
	
	std::vector<double> intArr;

	for (int i = 0; i < SIZE; i++) {
		double elmnt = static_cast<double>(rand() % 10000) / 100.0;
		intArr.emplace_back(elmnt);
	}

	selection_sort_template(&intArr);

	std::cout << "Sorted vector:" << std::endl;

	for (auto it = intArr.begin(); it != intArr.end(); it++) {
		std::cout << *(it) << std::endl;
	}
}

void selection_sort(int* arr, int size)
{
	if (size <= 0) return;

	for (int i = 0; i < size; i++) {
		int min_temp = arr[i];
		int min_index = i;
		for (int j = i+1; j < size; j++) {
			if (arr[j] < min_temp) {
				min_temp = arr[j];
				min_index = j;
			}
		}
		arr[min_index] = arr[i];
		arr[i] = min_temp;
	}
}

template <typename Comparable>
void selection_sort_template(std::vector<Comparable>* vec_ptr)
{
	if (vec_ptr == nullptr || vec_ptr->size() <= 0) return;

	size_t size = vec_ptr->size();

	for (size_t i = 0; i < size; i++) {
		Comparable min_temp = vec_ptr->at(i);
		size_t min_index = i;
		for (size_t j = i + 1; j < size; j++) {
			if (vec_ptr->at(j) < min_temp) {
				min_temp = vec_ptr->at(j);
				min_index = j;
			}
		}
		if (min_index != i) {
			std::swap(vec_ptr->at(i), vec_ptr->at(min_index));
		}
	}
}