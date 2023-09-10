#include "MaxHeapVector.h"
#include <iostream>

int main()
{
	MaxHeapVector bigV;

	bigV.insert(1);
	bigV.insert(2);
	bigV.insert(3);
	bigV.insert(4);
	bigV.insert(5);
	bigV.insert(6);
	bigV.insert(1);

	std::cout << "Max: " << bigV.findMax() << std::endl;
	std::cout << "Is empty" << bigV.isEmpty() << std::endl;
	std::cout << "Size: " << bigV.size() << std::endl;
	bigV.deleteMax();
	std::cout << "Max: " << bigV.findMax() << std::endl;
	std::cout << "Is empty" << bigV.isEmpty() << std::endl;
	std::cout << "Size: " << bigV.size() << std::endl;
}