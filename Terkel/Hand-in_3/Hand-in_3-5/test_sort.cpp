#include <iostream>
#include <vector>
#include "sort.h"
#include <time.h>

using namespace std;

void checkSort(const vector<int>& a) {
	for (int i = 0; i < a.size() - 1; ++i) {
		if (a[i] > a[i + 1]) {
			cout << "Error at " << i << endl;
		}
	}
	cout << "Finished checksort" << endl;
}


template <typename AnyType>
void permute(vector<AnyType>& a) {
	for (int j = 1; j < a.size(); ++j) {
		swap(a[j], a[rand() % j]);
	}
}

template <typename AnyType>
void selectionSort(vector<AnyType>& a) {
	size_t size = a.size();
	for (int i = 0; i < (size-1); ++i) {
		AnyType temp = a[i];
		int index = i;
		for (int j = (i + 1); j < size; ++j)
		{
			if (a[j] < temp)
			{
				temp = a[j];
				index = j;
			}
		}
		swap(a[i], a[index]);
	}
}

int main() {
	const int NUM_ITEMS = 1000;

	vector<int>a(NUM_ITEMS);
	for (int i = 1; i < a.size(); ++i) {
		a[i] = a[i - 1] + 'a';
	}

	for (int theSeed = 0; theSeed < 10; ++theSeed) {
		srand(time(0) + theSeed);

		permute(a);
		insertionSort(a);
		cout << "Insertion sort: ";
		checkSort(a);

		permute(a);
		insertionSort(begin(a), end(a));
		cout << "Insertion sort with iterator: ";
		checkSort(a);

		permute(a);
		mergeSort(a);
		cout << "Merge sort: ";
		checkSort(a);

		permute(a);
		quickSort(a);
		cout << "Quick sort: ";
		checkSort(a);

		permute(a);
		selectionSort(a);
		cout << "Selection sort: ";
		checkSort(a);
	}

	return 0;
}
