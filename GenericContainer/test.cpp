//#include <iostream>
//#include <cassert>
//#include <vector>
//#include <algorithm>
//#include <functional>
//#include <chrono>
//#include <iomanip>
//#include <set>
//
//#include "Set.h"
//
//#define ELEMENT_COUNT 10000
//int arr[ELEMENT_COUNT];
//
//void GenerateRandomValues() {
//	for (int index = 0; index < ELEMENT_COUNT; ++index) {
//		arr[index] = rand();
//	}
//}
//
//void SetInsertionTest(const std::vector<int>& arr) {
//	GenericContainers::Set<int> set;
//	std::vector<int> tmp = arr;
//
//	for (int index = 0; index < tmp.size(); ++index) {
//		set.Insert(tmp[index]);
//	}
//
//	std::set<int> stdSet(tmp.begin(), tmp.end());
//	tmp.assign(stdSet.begin(), stdSet.end());
//
//	for (int index = 0; index < tmp.size(); ++index) {
//		assert(set.Get(index) == tmp[index]);
//	}
//}
//
//int main() {
//	SetInsertionTest(std::vector<int>{7, 6, 5});
//	SetInsertionTest(std::vector<int>{10, 5, 15, 3, 7, 12, 20});
//	SetInsertionTest(std::vector<int>{1, 2, 3, 4, 5});
//	SetInsertionTest(std::vector<int>{5, 4, 3, 2, 1});
//	SetInsertionTest(std::vector<int>{1, 3, 2, 5, 4});
//	SetInsertionTest(std::vector<int>{50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 90, 5, 15, 23, 27, 33, 37, 43, 47, 53, 57, 63, 67, 73, 77, 85, 95});
//	SetInsertionTest(std::vector<int>{100, 50, 150, 25, 75, 125, 175, 12, 37, 62, 87, 112, 137, 162, 187, 6, 18, 31, 43, 56, 68, 81, 93, 106, 118, 131, 143, 156, 168, 181, 193});
//	SetInsertionTest(std::vector<int>{5, 5, 6});
//
//	std::set<int> stdSet;
//	GenericContainers::Set<int> mySet;
//
//	double stdSetTime = 0;
//	double mySetTime = 0;
//
//	GenerateRandomValues();
//	for (int index = 0; index < ELEMENT_COUNT; ++index) {
//		auto begin = std::chrono::high_resolution_clock().now();
//		stdSet.insert(arr[index]);
//		auto end = std::chrono::high_resolution_clock().now();
//
//		stdSetTime += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
//
//		begin = std::chrono::high_resolution_clock().now();
//		mySet.Insert(arr[index]);
//		end = std::chrono::high_resolution_clock().now();
//
//		mySetTime += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
//	}
//
//	std::cout << "std::set<int> average insertion time: " << std::setprecision(5) << std::fixed << stdSetTime / ELEMENT_COUNT << " microseconds\n";
//	std::cout << "GenericContainers::Set<int> average insertion time: " << std::setprecision(5) << std::fixed << mySetTime / ELEMENT_COUNT << " microseconds\n";
//	std::cout << "---------\n";
//
//	for (int index = 0; index < mySet.Size(); ++index) {
//		auto begin = std::chrono::high_resolution_clock().now();
//		std::set<int>::iterator it = stdSet.begin();
//		std::advance(it, index);
//		int x = *it;
//		auto end = std::chrono::high_resolution_clock().now();
//
//		stdSetTime += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
//
//		begin = std::chrono::high_resolution_clock().now();
//		mySet.Get(index);
//		end = std::chrono::high_resolution_clock().now();
//
//		mySetTime += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
//	}
//	std::cout << "std::set<int> average Get time: " << std::setprecision(5) << std::fixed << stdSetTime / ELEMENT_COUNT << " microseconds\n";
//	std::cout << "GenericContainers::Set<int> average Get time: " << std::setprecision(5) << std::fixed << mySetTime / ELEMENT_COUNT << " microseconds\n";
//	
//	std::cout << "std::set<int> size: " << sizeof(stdSet) + stdSet.size() * sizeof(int) << " bytes\n";
//	std::cout << "GenericContainers::Set<int> size: " << sizeof(mySet) + mySet.Size() * sizeof(int) << " bytes\n";
//
//	return 0;
//}