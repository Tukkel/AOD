#include <iostream>
#include <stdexcept>
#include <chrono>
#include "matrix_class.h"
#include "stdlib.h"
using namespace std;

#define ROWS		20000
#define COLS		20000

int main(void) {

	Matrix<int> mat(ROWS, COLS);
	int element = 1;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			mat[i][j] = element;
			element++;
		}
	}

	long long elmnt = 400000000;

	auto start = std::chrono::high_resolution_clock::now();

	cout << (mat.isElementStored(elmnt) ? "Element is in matrix" : "Element is not in matrix") << endl;

	auto end = std::chrono::high_resolution_clock::now();

	chrono::duration<double> duration = end - start;
	double seconds = duration.count();

	cout << "Time to run through algorithm: " << seconds << " seconds" << std::endl;
}
