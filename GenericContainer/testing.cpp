#include "LightweightSet.h"
#include "Set.h"
#include <iostream>

int main() {
	using namespace GenericContainers;

	Set<int> mySet;

	mySet.Insert(5);
	mySet.Insert(8567);
	mySet.Insert(5456);
	mySet.Insert(13);
	mySet.Insert(856);

	mySet.Remove(8567);
	mySet.Remove(13);

	mySet.Insert(15);
	mySet.Insert(549);
	mySet.Insert(15);

	mySet.Remove(856);

	mySet.Remove(15);
	mySet.Remove(15);

	return 0;
}