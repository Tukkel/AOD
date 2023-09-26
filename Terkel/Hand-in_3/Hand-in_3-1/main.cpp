#include <iostream>

bool findInIntArray(int* array, size_t size, int search)
{
	if (size < 1)
	{
		return false;
	}
	if (array[size-1] == search)
	{
		return true;
	}
	else
	{
		findInIntArray(array, size - 1, search);
	}
}

int findMinInIntArray(int* array, size_t size)
{
	if (size == 0)
	{
		return 0;
	}
	if (size == 1)
	{
		return array[0];
	}
	int min = findMinInIntArray(array, size - 1);
	if (array[size - 1] < min)
	{
		return array[size - 1];
	}
	else
	{
		return min;
	}
}

int findMaxInIntArray(int* array, size_t size)
{
	if (size == 0)
	{
		return 0;
	}
	if (size == 1)
	{
		return array[0];
	}
	int max = findMinInIntArray(array, size - 1);
	if (array[size - 1] > max)
	{
		return array[size - 1];
	}
	else
	{
		return max;
	}
}

int main(void)
{
	const size_t N = 10;
	int array[N];
	for (size_t i = 0; i < N; i++)
	{
		array[i] = i+2;
	}

	std::cout << findInIntArray(array, N, 4) << std::endl;
	std::cout << findMinInIntArray(array, N) << std::endl;
	std::cout << findMaxInIntArray(array, N) << std::endl;
	std::cout << findInIntArray(array, N, 1) << std::endl;

	return 0;
}