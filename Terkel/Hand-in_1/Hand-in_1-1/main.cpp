#include <iostream>
#include <vector>
#include <cstdlib>

const int M = 1000;
const int N = 10000;

using namespace std;

int main() {
	srand(time(NULL));

	vector<int> arr;
	int gen;
	int matches = 0;

	for (size_t i = 0; i < M; i++)
	{
		arr.push_back(rand() % (M * 10));
	}


	for (size_t i = 0; i < N; i++)
	{
		gen = rand() % (M * 10);
		for (auto it = arr.begin(); it < arr.end(); it++)
		{
			if (*it == gen)
			{
				matches++;
				break;
			}
		}
	}

	cout << matches;

	return 0;
}