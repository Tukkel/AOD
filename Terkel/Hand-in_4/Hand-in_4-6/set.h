#include <vector>
#include "binary_search_tree.h"

using namespace std;

template<typename Comparable>
class Set {
private:
	size_t theSize;
	BinarySearchTree<Comparable> tree;

public:
	Set() { }

	~Set() { clear(); }

	Set(const Set& s) {
		//Set copy(s);
		//std::swap(*this, copy);
	}

	void clear() {
		tree.makeEmpty();
		theSize = 0;
	}

	size_t size() const {
		return theSize;
	}

	bool empty() const {
		return theSize == 0;
	}

	void push(const Comparable& t) {
		tree.insert(t);
	}

	friend class BinarySearchTree<Comparable>;
	typedef typename BinarySearchTree<Comparable>::iterator iterator;

	iterator begin() const {
		return tree.findMin();
	}

	iterator end() const {
		return nullptr;
	}

	iterator insert(const Comparable& t) {
		return tree.insert(t);
	}

	iterator find(const Comparable& t) {
		return tree.find(t);
	}

	iterator erase(iterator& itr) {
		return tree.erase(itr);
	}
};
