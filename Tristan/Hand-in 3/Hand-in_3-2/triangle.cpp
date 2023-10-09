#include <iostream>

void triangle(int m, int n);



int main()
{
	triangle(3, 8);
}

void printStars(int n) {
    if (n <= 0) {
        return;
    }

    for (int i = 0; i < n; i++) {
        std::cout << '*';
    }

    std::cout << std::endl;
    printStars(n - 1);
}

void triangle(int m, int n) {
    if (m <= n) {
        printStars(m);
        triangle(m + 1, n);
        printStars(m);
    }
}

//void triangle(int m, int n, int start)
//{
//	if (m <= n) {
//		for (int i = 0; i < m; i++) {
//			std::cout << "*";
//		}
//		std::cout << std::endl;
//		triangle(++m, n, start);
//	}
//
//	else if (m >= n) {
//		if (n < start) {
//			return;
//		}
//
//		for (int i = 0; i < n; i++) {
//			std::cout << "*";
//		}
//		std::cout << std::endl;
//		triangle(m, --n, start);
//	}
//}