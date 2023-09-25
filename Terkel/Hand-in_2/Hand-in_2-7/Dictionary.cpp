#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary()
{
	size_ = 7;
	for (size_t i = 0; i < size_; i++)
	{
		dictionary_.push_back(make_pair("", 0));
	}
	elements_ = 0;
}

Dictionary::~Dictionary()
{
	dictionary_.clear();
}

bool Dictionary::insert(string x)
{
	if (contains(x))
	{
		return false;
	}
	size_t hash_value = hash(x);
	size_t index = hash_value % size_;
	while (dictionary_[index].second != 0)
	{
		index++;
		if (index == size_)
		{
			index = 0;
		}
	}
	dictionary_[index].first = x;
	dictionary_[index].second = hash_value;
	elements_++;

	if ((double)elements_ / size_ > 0.7)
	{
		rehash();
	}

	return true;
}

bool Dictionary::contains(string x) const
{
	size_t index = hash(x) % size_;
	while (dictionary_[index].second != 0)
	{
		if (dictionary_[index].first == x)
		{
			return true;
		}
		index++;
		if (index == size_)
		{
			index = 0;
		}
	}
	return false;
}

bool Dictionary::remove(string x)
{
	size_t index = hash(x) % size_;
	while (dictionary_[index].second != 0)
	{
		if (dictionary_[index].first == x)
		{
			dictionary_[index].first = "";
			dictionary_[index].second = 0;
			elements_--; 
			return true;
		}
		index++;
		if (index == size_)
		{
			index = 0;
		}
	}
	return false;
}

size_t Dictionary::hash(string x) const
{
	size_t hash = 0;
	for (size_t i = 0; i < x.length(); i++)
	{
		hash = (hash * 31) + x[i];
	}
	return hash;
}

void Dictionary::rehash()
{
	size_t newSize = nextPrime(size_ * 2);
	vector<pair<string, size_t>> newDictionary;
	size_t index;
	for (size_t i = 0; i < newSize; i++)
	{
		newDictionary.push_back(make_pair("", 0));
	}
	for (size_t i = 0; i < size_; i++)
	{
		if (dictionary_[i].second != 0)
		{
			index = dictionary_[i].second % newSize;
			newDictionary[index].first = dictionary_[i].first;
			newDictionary[index].second = dictionary_[i].second;
		}
	}
	size_ = newSize;
	dictionary_ = newDictionary;
}

// Copy from https://www.geeksforgeeks.org/program-to-find-the-next-prime-number/
// C++ implementation of the approach

// Function that returns true if n
// is prime else returns false
bool Dictionary::isPrime(size_t n)
{
	// Corner cases
	if (n <= 1)  return false;
	if (n <= 3)  return true;

	// This is checked so that we can skip 
	// middle five numbers in below loop
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

// Function to return the smallest
// prime number greater than N
size_t Dictionary::nextPrime(size_t N)
{

	// Base case
	if (N <= 1)
		return 2;

	size_t prime = N;
	bool found = false;

	// Loop continuously until isPrime returns
	// true for a number greater than n
	while (!found) {
		prime++;

		if (isPrime(prime))
			found = true;
	}

	return prime;
}
