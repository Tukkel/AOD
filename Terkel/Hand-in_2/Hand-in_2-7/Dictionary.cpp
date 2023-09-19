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
}

bool Dictionary::insert(std::string x)
{
	return false;
}

bool Dictionary::contains(std::string x) const
{
	size_t index = hash(x)%size_;
	if (dictionary_[index].second == 0)
	{
		return false;
	}
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

bool Dictionary::remove(std::string x)
{
	return false;
}

size_t Dictionary::hash(std::string x) const
{
	size_t hash = 0;
	for (size_t i = 0; i < x.length(); i++)
	{
		hash = (hash * 31) + x[i];
	}
	return hash;
}
