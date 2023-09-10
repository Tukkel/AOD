#include "VecMaxHeap.h"
#include "ListMaxHeap.h"
#include <iostream>

using namespace std;

int main(void) {
	ListMaxHeap test;

	cout << test.isEmpty() << endl;
	cout << test.size() << endl << endl;

	test.insert(11);
	test.insert(33);
	test.insert(22);

	cout << test.isEmpty() << endl;
	cout << test.size() << endl;
	cout << test.findMax() << endl;
	cout << test.deleteMax() << endl << endl;

	cout << test.findMax() << endl << endl << endl;

	return 0;
}