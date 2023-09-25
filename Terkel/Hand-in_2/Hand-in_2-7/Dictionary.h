#pragma once
#include <vector>
#include <string>
#include <iostream>

class Dictionary
{
public:
	Dictionary();
	~Dictionary();
	bool insert(std::string x);
	bool contains(std::string x) const;
	bool remove(std::string x);
private:
	size_t hash(std::string x) const;
	void rehash();
	bool isPrime(size_t n);
	size_t nextPrime(size_t N);
	std::vector<std::pair<std::string, size_t>> dictionary_;
	size_t elements_;
	size_t size_;
};

