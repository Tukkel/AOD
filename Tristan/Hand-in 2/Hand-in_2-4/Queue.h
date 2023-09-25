#pragma once

#include "stack_class.h"

template <typename Object>
class Queue
{
public:
	Queue() {
		stack = new Stack<Object>();
	}

	~Queue() {
		delete stack;
	}

	bool empty() { return (stack->empty()); };

	Object front() { 
		assert(!(stack->empty()));

		Stack<Object> tempStack;

		while (!(stack->empty()))
		{
			tempStack.push(stack->pop());
		}

		Object front_element = tempStack.top();

		while (!(tempStack.empty()))
		{
			stack->push(tempStack.pop());
		}

		return front_element;
	}

	Object get() {
		assert(!(stack->empty()));

		Stack<Object> tempStack;

		while (!(stack->empty()))
		{
			tempStack.push(stack->pop());
		}

		Object front_element = tempStack.pop();

		while (!(tempStack.empty()))
		{
			stack->push(tempStack.pop());
		}

		return front_element;
	}

	void put(const Object x) {
		stack->push(x);
	}

	int size() { return stack->size(); }

private:
	Stack<Object> *stack;
};

