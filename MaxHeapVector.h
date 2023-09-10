#pragma once

#include "MaxHeap.H"
#include <vector>

class MaxHeapVector : public MaxHeap
{
public:
	MaxHeapVector();
	virtual ~MaxHeapVector();
	bool isEmpty() const override;
	int size() override;
	void insert(const int x) override;
	const int findMax() const override;
	int deleteMax() override;
private:
	std::vector<int> maxHeapVector;
};