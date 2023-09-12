#include "Stack.h"
#include <iostream>

using namespace std;

int main(void)
{
	Stack<int> intTest(1);
	intTest.push(1).push(2).push(3).push(4).push(5).push(6).push(7).push(8).push(9);
	cout << intTest.peek() << endl;
	cout << intTest.pop() << endl;
	cout << intTest.pop() << endl;
	cout << intTest.peek() << " " << intTest.pop() << " " << intTest.pop() << endl;
	return 0;
}