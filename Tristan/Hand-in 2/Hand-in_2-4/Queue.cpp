#include "Queue.h"
#include <chrono>
#include <iostream>
#include <random>

int main()
{
	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_int_distribution<int> dist(1, 100);

	Queue<int> queue;

	int n = 10000;

	std::cout << "Number of elements n: " << n << std::endl;

	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < n; i++)
	{
		int randomNumber = dist(mt);
		if (i == 0)
			std::cout << "First element: " << randomNumber << std::endl;

		queue.put(randomNumber);
	}

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration = end - start;
	double seconds = duration.count();

	std::cout << "Size of queue: " << queue.size() << std::endl;
	std::cout << "Time to push " << n << " numbers: " << seconds << " seconds" << std::endl;

	start = std::chrono::high_resolution_clock::now();

	int front_element = queue.front();

	end = std::chrono::high_resolution_clock::now();

	duration = end - start;

	seconds = duration.count();

	std::cout << "Time to find front element " << front_element << " : " << seconds << " seconds" << std::endl;

	start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < n; i++)
	{
		queue.get();
	}

	end = std::chrono::high_resolution_clock::now();

	duration = end - start;

	seconds = duration.count();

	std::cout << "Time to clear queue: " << seconds << " seconds" << std::endl;
}