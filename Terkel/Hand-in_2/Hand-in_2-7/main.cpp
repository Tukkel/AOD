#include "Dictionary.h"
#include <iostream>

using namespace std;

int main(void)
{
	Dictionary test;

	cout << "insert abc: " << test.insert("abc") << endl;
	cout << "insert def: " << test.insert("def") << endl;
	cout << "insert ghi: " << test.insert("ghi") << endl;

	cout << "find def: " << test.contains("def") << endl;
	cout << "find bcd: " << test.contains("bcd") << endl;

	cout << "insert jkl: " << test.insert("jkl") << endl;
	cout << "insert ghi: " << test.insert("ghi") << endl;

	cout << "remove jkl: " << test.remove("jkl") << endl;
	cout << "remove fgh: " << test.remove("fgh") << endl;

	cout << "find jkl: " << test.contains("jkl") << endl;

	cout << "insert jkl: " << test.insert("jkl") << endl;
	cout << "insert mno: " << test.insert("mno") << endl;
	cout << "insert pqr: " << test.insert("pqr") << endl;

	return 0;
}