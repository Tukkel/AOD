#pragma once
#include <vector>
#include <string>

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
	std::vector<std::pair<std::string, size_t>> dictionary_;
	size_t elements_;
	size_t size_;
};

