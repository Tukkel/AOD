#pragma once
template <class T>
class Stack
{
public:
	Stack(size_t size = 100);
	Stack<T>& push(T x);
	T pop();
	T peek();
private:
	T* stack_;
	size_t size_;
	size_t position_;
};

template<class T>
Stack<T>::Stack(size_t size)
{
	position_ = 0;

	if (size > 0)
	{
		size_ = size;
	}
	else
	{
		size_ = 100;
	}

	stack_ = new T[size_];
}


template<class T>
Stack<T>& Stack<T>::push(T x)
{
	if (position_ == size_)
	{
		size_ *= 2;
		T* newStack;
		newStack = new T[size_];

		for (size_t i = 0; i < (size_ / 2); i++)
		{
			newStack[i] = stack_[i];
		}
		delete[] stack_;
		stack_ = newStack;
	}

	stack_[position_] = x;
	position_++;
	return *this;
}

template<class T>
T Stack<T>::pop()
{
	if (position_ == 0)
	{
		return stack_[position_];
	}
	position_--;
	return stack_[position_];
}

template<class T>
T Stack<T>::peek()
{
	return stack_[position_ - 1];
}