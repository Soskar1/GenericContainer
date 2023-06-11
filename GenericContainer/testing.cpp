#include "LightweightSet.h"
#include "Set.h"
#include <iostream>

int main() {
	using namespace GenericContainers;

	LightweightSet<int> mySet;

	mySet.Insert(2);
	mySet.Insert(2);
	mySet.Insert(2);
	mySet.Insert(4);
	mySet.Insert(4);
	mySet.Insert(6);
	mySet.Insert(6);
	mySet.Insert(6);

	for (int i = 0; i < mySet.Size(); ++i) {
		std::cout << mySet.Get(i) << " ";
	}

	std::cout << std::endl;

	mySet.RemoveFirst();
	mySet.Remove(5);
	mySet.Remove(size_t(5));
	mySet.RemoveLast();

	mySet.Insert(2);
	mySet.Insert(2);
	mySet.Insert(2);
	mySet.Insert(4);
	mySet.Insert(4);
	mySet.Insert(6);
	mySet.Insert(6);
	mySet.Insert(6);

	mySet.Insert(2);
	mySet.Insert(2);
	mySet.Insert(2);
	mySet.Insert(4);
	mySet.Insert(4);
	mySet.Insert(6);
	mySet.Insert(6);
	mySet.Insert(6);

	for (int i = 0; i < mySet.Size(); ++i) {
		std::cout << mySet.Get(i) << " ";
	}

	std::cout << std::endl;

	mySet.Clear();

	for (int i = 0; i < mySet.Size(); ++i) {
		std::cout << mySet.Get(i) << " ";
	}

	std::cout << std::endl;

	std::cout << mySet.Contains(6);

	return 0;
}