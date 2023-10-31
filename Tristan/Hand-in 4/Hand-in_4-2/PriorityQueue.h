#pragma once
#include "binary_heap.h"

template <typename Comparable>
class PriorityQueue {
public:
	BinaryHeap<Comparable> bh;

	void pop()
	{
		bh.deleteMax();
	}

	void push(const Comparable& x)
	{
		bh.insert(x);
	}

	const Comparable& top() const
	{
		return bh.findMax();
	}

	bool empty()
	{
		return bh.isEmpty();
	}

	void clear()
	{
		while (!empty())
			bh.deleteMax();
	}
};