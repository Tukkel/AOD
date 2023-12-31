#include <iostream>
#include <vector>
#include <stdlib.h>
#include "sort.h"
#include <time.h>
#include <algorithm>


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

int main() {
	const int NUM_ITEMS = 1000000;

	vector<int>a(NUM_ITEMS);
	vector<int>b(NUM_ITEMS);

	clock_t start, stop;

	for (int i = 1; i < a.size(); ++i) {
		a[i] = a[i - 1] + 'a';
	}

	for (int theSeed = 0; theSeed < 10; ++theSeed) {
		srand(theSeed);

		permute(a);

		b = a;
		start = clock();
		introSort(b);
		stop = clock();
		cout << "Sorting with intro sort with seed " << theSeed << " took: " << ((double)(stop - start) / CLOCKS_PER_SEC) << " seconds. ";
		checkSort(b);

		b = a;
		start = clock();
		sort(b.begin(), b.end());
		stop = clock();
		cout << "Sorting with stlsort with seed " << theSeed << " took: " << ((double)(stop - start) / CLOCKS_PER_SEC) << " seconds. ";
		checkSort(b);

		cout << endl;
	}

	return 0;
}
