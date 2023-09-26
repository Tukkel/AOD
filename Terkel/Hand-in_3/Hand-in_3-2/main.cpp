#include <iostream>

using namespace std;

int min;

void triangle(size_t m, size_t n)
{
	if (m > n)
	{
		return;
	}

	for (size_t i = 0; i < m; i++)
	{
		cout << "* ";
	}
	cout << endl;

	triangle(m + 1, n);

	for (size_t i = 0; i < m; i++)
	{
		cout << "* ";
	}
	cout << endl;
}

int main(void)
{
	triangle(4, 6);
	return 0;
}