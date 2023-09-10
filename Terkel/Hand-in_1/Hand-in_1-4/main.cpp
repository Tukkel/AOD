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

	VecMaxHeap testVec;

	cout << testVec.isEmpty() << endl;
	cout << testVec.size() << endl << endl;

	testVec.insert(11);
	testVec.insert(33);
	testVec.insert(22);

	cout << testVec.isEmpty() << endl;
	cout << testVec.size() << endl;
	cout << testVec.findMax() << endl;
	cout << testVec.deleteMax() << endl << endl;

	cout << testVec.findMax() << endl << endl << endl;

	return 0;
}