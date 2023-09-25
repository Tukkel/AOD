#include "MaxHeapVector.h"

MaxHeapVector::MaxHeapVector()
{

}

MaxHeapVector::~MaxHeapVector()
{

}

bool MaxHeapVector::isEmpty() const
{
	return maxHeapVector.empty();
}

int MaxHeapVector::size()
{
	int size = 0;
	for (std::vector<int>::iterator it = maxHeapVector.begin(); it != maxHeapVector.end(); it++)
	{
		size++;
	}
	return size;
}

void MaxHeapVector::insert(const int x)
{
	maxHeapVector.emplace_back(x);
}

const int MaxHeapVector::findMax() const
{
	int maxVal = 0;
	if (isEmpty())
		return -1;
	else
	{
		for (auto it = maxHeapVector.begin(); it != maxHeapVector.end(); it++)
		{
			if (*it > maxVal)
				maxVal = *it;
		}
		return maxVal;
	}
}

int MaxHeapVector::deleteMax()
{
	int maxVal = 0;
	
	std::vector<int>::iterator maxValPos = maxHeapVector.begin();

	if (isEmpty())
		return -1;
	else
	{
		for (std::vector<int>::iterator it = maxHeapVector.begin(); it != maxHeapVector.end(); it++)
		{
			if (*it > maxVal)
			{
				maxVal = *it;
				maxValPos = it;
			}
		}
		maxHeapVector.erase(maxValPos);

		return maxVal;
	}
}
