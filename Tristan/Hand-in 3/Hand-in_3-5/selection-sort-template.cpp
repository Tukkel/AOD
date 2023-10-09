#include <iostream>
#include <stdlib.h>
#include <vector>

#define SIZE 100

template <typename Comparable>
void selection_sort_template(std::vector<Comparable>* vec_ptr);

int main()
{
	srand(time(NULL));
	
	std::vector<double> doubleArr;

	for (int i = 0; i < SIZE; i++) {
		double elmnt = static_cast<double>(rand() % 10000) / 100.0;
		doubleArr.emplace_back(elmnt);
	}

	selection_sort_template(&doubleArr);

	std::cout << "Sorted vector:" << std::endl;

	for (auto it = doubleArr.begin(); it != doubleArr.end(); it++) {
		std::cout << *(it) << std::endl;
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