#include "LightweightSet.h"
#include "Set.h"
#include <iostream>

int main() {
	using namespace GenericContainers;

	LightweightSet<int> mySet;

	mySet.Insert(4);
	mySet.Insert(4);
	mySet.Insert(4);
	mySet.Insert(4);
	mySet.Insert(4);
	mySet.Insert(4);
	mySet.Insert(2);
	mySet.Insert(9);
	mySet.Insert(3);

	for (int i = 0; i < mySet.Size(); ++i) {
		std::cout << mySet.Get(i) << " ";
	}

	std::cout << std::endl;

	std::cout << mySet.GetLast();

	return 0;
}