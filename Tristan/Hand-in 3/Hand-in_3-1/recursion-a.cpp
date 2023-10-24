#include <iostream>

const int x_ = 10;

bool findX(int* arr, int num);
bool findXrecursive(int* arr, int num, int index);

int main() {

	int arr[x_];

	for (int i = 0; i < x_; i++) {
		arr[i] = i;
	}

	int number = 6;

	if (findXrecursive(arr, x_, 9)) {
		std::cout << "The number " << number << " is in the array." << std::endl;
	}
	else {
		std::cout << "The number " << number << " is NOT in the array." << std::endl;
	}
}

bool findX(int* arr, int num) {
	for (int i = 0; i < x_; i++) {
		if (arr[i] == num) {
			return true;
		}
	}
	return false;
}

bool findXrecursive(int* arr, int size, int num) {
	if (size == 0) {
		return false;
	}
	else if (*arr == num) {
		return true;
	}	
	
	findXrecursive(++arr, size-1, num);
}