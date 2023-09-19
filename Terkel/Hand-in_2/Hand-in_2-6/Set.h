#ifndef _SET_H_
#define _SET_H_

#include "double_list.h"

template <class T>
class Set
{
public:
	Set();
	~Set();
	bool insert(T x);
	bool contains(T x) const;
	bool remove(T x);
private:
	List<T> * set_;
	size_t elements_;
};

#include "Set.cpp"

#endif
