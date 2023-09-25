#include <iostream>
#include <stdexcept>
#include "matrix_class.h"
#include "stdlib.h"
using namespace std;

#define ROWS		5
#define COLS		6

int main(void) {

	Matrix<int> mat(ROWS, COLS);

	for (int i = 0; i < ROWS; i++) {             // randomize mat
		for (int j = 0; j < COLS; j++) {
			mat[i][j] = 9;
		}
	}

	cout << (mat.isElementStored(9) ? "true" : "false") << endl;

	cout << endl << mat << endl;
}
