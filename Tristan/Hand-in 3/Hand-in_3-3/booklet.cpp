#include <iostream>

void bookletPrint(int startPage, int endPage);

int main()
{
	bookletPrint(1,32);
}

void bookletPrint(int startPage, int endPage)
{
	if (startPage <= endPage) {
		std::cout << "Sheet " << (startPage+1)/2 << " contains pages " << startPage << ", " << startPage+1 << ", " << endPage-1 << ", " << endPage << std::endl;
	}
	else {
		return;
	}
	bookletPrint(startPage+2, endPage-2);
}
