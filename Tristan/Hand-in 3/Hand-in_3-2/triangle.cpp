#include <iostream>

void triangle(int m, int n, int start);

int main()
{
	triangle(3, 8, 3);
}

void triangle(int m, int n, int start)
{
	if (m <= n) {
		for (int i = 0; i < m; i++) {
			std::cout << "*";
		}
		std::cout << std::endl;
		triangle(++m, n, start);
	}

	else if (m >= n) {
		if (n < start) {
			return;
		}

		for (int i = 0; i < n; i++) {
			std::cout << "*";
		}
		std::cout << std::endl;
		triangle(m, --n, start);
	}
}