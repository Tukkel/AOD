#include "VecMaxHeap.h"

using namespace std;

VecMaxHeap::VecMaxHeap()
{
    arr = new int[0];
    arrSize = 0;
}

bool VecMaxHeap::isEmpty() const
{
    if (arrSize)
    {
        return false;
    }
    return true;
}

int VecMaxHeap::size()
{
    return arrSize;
}

void VecMaxHeap::insert(const int x)
{
    int* arrNew = new int[arrSize+1];
    
    for (size_t i = 0; i < (arrSize); i++)
    {
        arrNew[i] = arr[i];
    }
    arrNew[arrSize] = x;
    arrSize++;
    delete[] arr;
    arr = arrNew;
}

const int VecMaxHeap::findMax() const
{
    assert(arrSize > 0);
    int max = arr[0];
    for (size_t i = 1; i < arrSize; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int VecMaxHeap::deleteMax()
{
    assert(arrSize > 0);
    int max = arr[0];
    int maxIndex = 0;
    for (size_t i = 1; i < arrSize; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }
    }
    arrSize--;
    int* arrNew = new int[arrSize];
    for (size_t i = 0; i < arrSize; i++)
    {
        if (i != maxIndex)
        {
            arrNew[i] = arr[i];
        }
    }
    if (arrSize != maxIndex)
    {
        arrNew[maxIndex] = arr[arrSize];
    }
    delete[] arr;
    arr = arrNew;
    return max;
}
