#include "LightweightSet.h"
#include "Set.h"
#include <iostream>

int main() {
	using namespace GenericContainers;

	Set<int> mySet;

	mySet.Insert(2);
	mySet.Insert(2);
	mySet.Insert(2);
	mySet.Insert(4);
	mySet.Insert(6);
	mySet.Insert(6);
	mySet.Insert(6);
	mySet.Insert(6);
	mySet.Insert(7);
	mySet.Insert(8);
	mySet.Insert(8);
	mySet.Insert(12);
	mySet.Insert(15);
	mySet.Insert(15);

	mySet.Clear();

	std::cout << mySet.Contains(12);

	return 0;
}