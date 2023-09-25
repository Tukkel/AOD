#include "Queue.h"
#include <chrono>
#include <iostream>
#include <random>

int main()
{
	Test queue

	Queue<int> queue;

	int n = 10;

	for (int i = 0; i < n; i++)
	{
		int newNumber = i;

		std::cout << "Calling queue-put, new element " << newNumber << std::endl;

		queue.put(newNumber);
	}

	std::cout << "Calling queue.size(), size of queue: " << queue.size() << std::endl;
	std::cout << "Calling queue.front(), front element: " << queue.front() << std::endl;
	while (!(queue.empty()))
	{
		std::cout << "Calling queue.get(), element: " << queue.get() << std::endl;
	}

}