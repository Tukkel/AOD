#pragma once
#include <list>
#include <cassert>
#include "MaxHeap.h"

class ListMaxHeap : public MaxHeap
{
public:
	//Constructor
	ListMaxHeap();
	//Deconstructor
	~ListMaxHeap();
	// is the heap empty?
	bool isEmpty() const;
	// number of elements in the heap
	int size();
	// add an element to the heap
	void insert(const int x);
	// find the maximum element in the heap
	const int findMax() const;
	// delete and return the maximum element of the heap
	int deleteMax();
	// Clear data in list
	void clear();
private:
	struct Node {
		int data;
		Node* next;
	};
	size_t theSize;
	Node* head;
	Node* tail;
};