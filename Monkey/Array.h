#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;

template <typename Mytype>
class Array {

public:
	Array();
	Array(Mytype x, Mytype N);
	void setInfo(Mytype x, Mytype N);
	bool findMatch(Mytype x, Mytype N, Mytype k)const;
	Mytype getMax(Mytype k, Mytype N, Mytype maximum)const;
	Mytype getMin(Mytype k, Mytype N, Mytype minimum)const;
	void print()const;
	
private:
	Mytype x_, N_, k_; //x, N and k(Used for filling and checking vector
	Mytype maximum_; 
	Mytype minimum_;
	std::vector<Mytype> a_; //Vector used as an array
	int maxTal_ = 10000; //Max number in Vector
};


//Defualt contructor
template <typename Mytype>
Array<Mytype>::Array() {

}


//Used contructor in exercise
template <typename Mytype>
Array<Mytype>::Array(Mytype x, Mytype N) {

	setInfo(x, N);
	print();

}

//Filling of vector with size N and filling of parameters, that's going to be used for x, min and max.
template <typename Mytype>
void Array<Mytype>::setInfo(Mytype x, Mytype N) {

	//rand() bliver random efter tid
	srand(time(NULL));

	for (Mytype i = 0; i < N; i++) {
		a_.push_back(rand() % maxTal_ + 1);
		//std::cout << " " << a_[i] << ",";  (Was used to check what number was filled into the vector)
	}
	x_ = x;
	maximum_ = 0;
	minimum_ = maxTal_;
	k_ = 0;
}

//Looks for match in vector with x
template <typename Mytype>
bool Array<Mytype>::findMatch(Mytype x, Mytype N, Mytype k)const {

	if (k >= a_.size()) {
	}
	else {
		if (x != a_[k]) return findMatch(x, N, k + 1);
		else { return true + findMatch(x, N, k + 1); }
	}
}

//Finds Max number in vector
template <typename Mytype>
Mytype Array<Mytype>::getMax(Mytype k, Mytype N, Mytype maximum)const {
	if (k >= a_.size()) {
		return maximum;
	}
	else {
		if (maximum > a_[k]) {
			return getMax(k + 1, N, maximum);
		}
		else {
			maximum = a_[k];
			return getMax(k + 1, N, maximum);
		}
	}
}

//Finds Min number in vector
template <typename Mytype>
Mytype Array<Mytype>::getMin(Mytype k, Mytype N, Mytype minimum)const {
	if (k >= a_.size()) {
		return minimum;
	}
	else {
		if (minimum < a_[k]) {
			return getMin(k + 1, N, minimum);
		}
		else {
			minimum = a_[k];
			return getMin(k + 1, N, minimum);
		}
	}
}


//Prints x(if found or not), min and max out in terminal
template <typename Mytype>
void Array<Mytype>::print() const {

	if (findMatch(x_, N_, k_) == true) {
		std::cout << std::endl << " x is found";
	}
	else std::cout << std::endl << " x isn't found";

	std::cout << std::endl << " Max: " << getMax(k_, N_, maximum_);

	std::cout << std::endl << " Min: " << getMin(k_, N_, minimum_);
}