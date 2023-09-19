#include "Set.h"
#include <iostream>

using namespace std;

int main(void)
{
	Set<int> test;

	cout << "insert 2: " << test.insert(2) << endl;
	cout << "insert 4: " << test.insert(4) << endl;
	cout << "insert 6: " << test.insert(6) << endl;

	cout << "find 4: " << test.contains(4) << endl;
	cout << "find 5: " << test.contains(5) << endl;

	cout << "insert 8: " << test.insert(8) << endl;
	cout << "insert 6: " << test.insert(6) << endl;

	cout << "remove 8: " << test.remove(8) << endl;
	cout << "remove 3: " << test.remove(3) << endl;

	cout << "find 8: " << test.contains(8) << endl;

	return 0;
}