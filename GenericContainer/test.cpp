#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <chrono>
#include <iomanip>
#include <random>
#include <set>

#include "Set.h"

#define ELEMENT_COUNT 10000
std::vector<int> arr;

#define SPEED_TEST

void GenerateRandomValues() {
	for (int index = 0; index < ELEMENT_COUNT; ++index) {
		arr.push_back(rand());
	}
}

void SetInsertionTest(const std::vector<int>& arr) {
	GenericContainers::Set<int> set;
	std::vector<int> tmp = arr;

	for (int index = 0; index < tmp.size(); ++index) {
		set.Insert(tmp[index]);
	}

	std::set<int> stdSet(tmp.begin(), tmp.end());
	tmp.assign(stdSet.begin(), stdSet.end());

	for (int index = 0; index < tmp.size(); ++index) {
		assert(set.Get(index) == tmp[index]);
	}
}

void SetRemoveTest(const std::vector<int>& arr, const std::vector<int>& elementsToRemove) {
	GenericContainers::Set<int> set;
	std::vector<int> tmp = arr;

	for (int index = 0; index < tmp.size(); ++index) {
		set.Insert(tmp[index]);
	}

	std::set<int> stdSet(tmp.begin(), tmp.end());

	for (int index = 0; index < elementsToRemove.size(); ++index) {
		set.Remove(elementsToRemove[index]);
		stdSet.erase(elementsToRemove[index]);
	}

	tmp.assign(stdSet.begin(), stdSet.end());

	for (int index = 0; index < tmp.size(); ++index) {
		assert(set.Get(index) == tmp[index]);
	}
}

int main() {
#ifndef SPEED_TEST
	SetInsertionTest(std::vector<int>{7, 6, 5});
	SetInsertionTest(std::vector<int>{10, 5, 15, 3, 7, 12, 20});
	SetInsertionTest(std::vector<int>{1, 2, 3, 4, 5});
	SetInsertionTest(std::vector<int>{5, 4, 3, 2, 1});
	SetInsertionTest(std::vector<int>{1, 3, 2, 5, 4});
	SetInsertionTest(std::vector<int>{50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 90, 5, 15, 23, 27, 33, 37, 43, 47, 53, 57, 63, 67, 73, 77, 85, 95});
	SetInsertionTest(std::vector<int>{100, 50, 150, 25, 75, 125, 175, 12, 37, 62, 87, 112, 137, 162, 187, 6, 18, 31, 43, 56, 68, 81, 93, 106, 118, 131, 143, 156, 168, 181, 193});
	SetInsertionTest(std::vector<int>{5, 5, 6});

	SetRemoveTest(std::vector<int>{5, 6, 7}, std::vector<int>{5});
	SetRemoveTest(std::vector<int>{1, 2, 3, 4}, std::vector<int>{3});
	SetRemoveTest(std::vector<int>{1, 2, 3, 4, 5}, std::vector<int>{3, 4});
	SetRemoveTest(std::vector<int>{1, 2, 3, 4, 5}, std::vector<int>{1, 2, 3, 4, 5});

	SetRemoveTest(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100},
		std::vector<int>{11, 23, 37, 50, 62, 75, 89});
#else
	std::set<int> stdSet;
	GenericContainers::Set<int> mySet;

	double stdSetTime = 0;
	double mySetTime = 0;

	GenerateRandomValues();
	for (int index = 0; index < ELEMENT_COUNT; ++index) {
		auto begin = std::chrono::high_resolution_clock().now();
		stdSet.insert(arr[index]);
		auto end = std::chrono::high_resolution_clock().now();

		stdSetTime += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

		begin = std::chrono::high_resolution_clock().now();
		mySet.Insert(arr[index]);
		end = std::chrono::high_resolution_clock().now();

		mySetTime += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	}

	std::cout << "std::set<int> average insertion time: " << std::setprecision(5) << std::fixed << stdSetTime / ELEMENT_COUNT << " microseconds\n";
	std::cout << "GenericContainers::Set<int> average insertion time: " << std::setprecision(5) << std::fixed << mySetTime / ELEMENT_COUNT << " microseconds\n";
	std::cout << "---------\n";

	stdSetTime = 0;
	mySetTime = 0;

	for (int index = 0; index < mySet.Size(); ++index) {
		auto begin = std::chrono::high_resolution_clock().now();
		std::set<int>::iterator it = stdSet.begin();
		std::advance(it, index);
		int x = *it;
		auto end = std::chrono::high_resolution_clock().now();

		stdSetTime += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

		begin = std::chrono::high_resolution_clock().now();
		mySet.Get(index);
		end = std::chrono::high_resolution_clock().now();

		mySetTime += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	}

	std::cout << "std::set<int> average Get time: " << std::setprecision(5) << std::fixed << stdSetTime / ELEMENT_COUNT << " microseconds\n";
	std::cout << "GenericContainers::Set<int> average Get time: " << std::setprecision(5) << std::fixed << mySetTime / ELEMENT_COUNT << " microseconds\n";
	std::cout << "---------\n";

	stdSetTime = 0;
	mySetTime = 0;

	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(arr), std::end(arr), rng);
	size_t initialSize = mySet.Size();
	for (int index = 0; index < mySet.Size(); ++index) {
		auto begin = std::chrono::high_resolution_clock().now();
		stdSet.erase(arr[index]);
		auto end = std::chrono::high_resolution_clock().now();

		stdSetTime += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

		begin = std::chrono::high_resolution_clock().now();
		mySet.Remove(arr[index]);
		end = std::chrono::high_resolution_clock().now();

		mySetTime += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	}

	std::cout << "std::set<int> average erase/remove time: " << std::setprecision(5) << std::fixed << stdSetTime / initialSize << " microseconds\n";
	std::cout << "GenericContainers::Set<int> average erase/remove time: " << std::setprecision(5) << std::fixed << mySetTime / initialSize << " microseconds\n";
#endif
	return 0;
}