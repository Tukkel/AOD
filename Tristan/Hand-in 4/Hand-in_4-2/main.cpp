#include <iostream>
#include "PriorityQueue.h"

int main() {

	PriorityQueue<int> maxPQ;

	for (int i = 0; i < 100; ++i) {
		maxPQ.push(i);
	}
	for (int i = 78; i > 15; i--) {
		maxPQ.push(i);
	}

	while (!maxPQ.empty()) {
		std::cout << maxPQ.top() << std::endl;
		maxPQ.pop();
	}

	if (maxPQ.empty())
		std::cout << "Priority queue is empty" << std::endl;
	else
		std::cout << "Prority queue is NOT empty" << std::endl;

	return 0;
}
