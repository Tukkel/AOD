#include "VecMaxHeap.h"

using namespace std;

VecMaxHeap::VecMaxHeap()
{
}

bool VecMaxHeap::isEmpty() const
{
    if (arr.empty())
    {
        return true;
    }
    return false;
}

int VecMaxHeap::size()
{
    return arr.size();
}

void VecMaxHeap::insert(const int x)
{
    arr.push_back(x);
}

const int VecMaxHeap::findMax() const
{
    return *max_element(arr.begin(), arr.end());
}

int VecMaxHeap::deleteMax()
{
    int max = findMax();
    arr.erase(max_element(arr.begin(), arr.end()));

    return max;
}
