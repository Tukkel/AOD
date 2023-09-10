#include "ListMaxHeap.h"

using namespace std;

ListMaxHeap::ListMaxHeap()
{
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->next = nullptr;
}

ListMaxHeap::~ListMaxHeap()
{
    clear();
    delete head;
    delete tail;
}

bool ListMaxHeap::isEmpty() const
{
    if (theSize) {
        return false;
    }
    else {
        return true;
    }
}

int ListMaxHeap::size()
{
    return (int)theSize;
}

void ListMaxHeap::insert(const int x)
{
    Node* p = new Node;
    p->data = x;
    p->next = head->next;
    head->next = p;
    theSize++;
}

const int ListMaxHeap::findMax() const
{
    assert(theSize > 0);
    Node* p = head->next;
    int max = p->data;
    while (p->next != tail)
    {
        p = p->next;
        if (p->data > max)
        {
            max = p->data;
        }
    }
    return max;
}

int ListMaxHeap::deleteMax()
{
    //Check there is data
    assert(theSize > 0);
    //Find max value and index
    int index = 0;
    int maxIndex = 0;
    Node* p = head->next;
    int max = p->data;
    while (p->next != tail)
    {
        p = p->next;
        index++;
        if (p->data > max)
        {
            max = p->data;
            maxIndex = index;
        }
    }
    //Delete index with max value
    p = head;
    index = 0;
    while (index != maxIndex)
    {
        p = p->next;
        index++;
    }
    Node* del = p->next;
    p->next = del->next;
    delete del;
    theSize--;

    return max;
}

void ListMaxHeap::clear() {
    Node* p = head->next;
    while (p != tail) {
        Node* t = p->next;
        delete p;
        p = t;
        head->next = t;
    }
}
