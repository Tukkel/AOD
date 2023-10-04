#include <iostream>
#include <vector>
#include "counting_sort.cpp"
#include <time.h>

using namespace std;

void countingSort(vector<size_t>& input, size_t k)
{
	vector<size_t> count(k + 1, 0);
	vector<size_t> output(input.size());

	for (int i = 0; i < input.size(); ++i)
	{
		size_t j = input[i];
		count[j]++;
	}

	for (int i = 1; i <= k; ++i)
	{
		count[i] += count[i - 1];
	}

	for (int i = (input.size() - 1); i >= 0; --i)
	{
		size_t j = input[i];
		count[j]--;
		output[count[j]] = input[i];
	}

	input = output;
}

void checkSort(const vector<size_t>& a) {
	for (int i = 0; i < a.size() - 1; ++i) {
		if (a[i] > a[i + 1]) {
			cout << "Error at " << i << endl;
		}
	}
	cout << "Finished checksort" << endl;
}

void permute(vector<size_t>& a) {
	for (int j = 1; j < a.size(); ++j) {
		swap(a[j], a[rand() % j]);
	}
}

int main() {
	const int NUM_ITEMS = 1000;
	const int MAX_VALUE = 500;

	vector<size_t>a(NUM_ITEMS);
	for (size_t i = 1; i < a.size(); ++i) {
		a[i] = a[i - 1] + 'a';
	}
	for (size_t i = 0; i < a.size(); ++i) {
		a[i] = a[i] % (MAX_VALUE+1);
	}

	for (int theSeed = 0; theSeed < 10; ++theSeed) {
		srand(time(0) + theSeed);

		permute(a);
		countingSort(a, MAX_VALUE);
		cout << "Counting sort: ";
		checkSort(a);
	}

	return 0;
}