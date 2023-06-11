#include <iostream>
#include <string>
#include "Set.h"

int main()
{
    GenericContainers::Set<int> intSet;
    intSet.Insert(5);
    intSet.Insert(20);
    intSet.Insert(1);

    std::cout << "size: " << intSet.Size() << std::endl;
    std::cout << "set contains 5: " << intSet.Contains(5) << std::endl;
    std::cout << "set contains 100: " << intSet.Contains(100) << std::endl;

    std::cout << "set[0] = " << intSet.Get(0) << std::endl;
    std::cout << "set[1] = " << intSet.Get(1) << std::endl;
    std::cout << "set[2] = " << intSet.Get(2) << std::endl;
    
    try {
        intSet.Get(3);
    }
    catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }

    intSet.Remove(5);
    std::cout << "size: " << intSet.Size() << std::endl;
    std::cout << "set contains 5: " << intSet.Contains(5) << std::endl;
    std::cout << "set[0] = " << intSet.Get(0) << std::endl;
    std::cout << "set[1] = " << intSet.Get(1) << std::endl;

    intSet.Edit(1, 40);
    std::cout << "size: " << intSet.Size() << std::endl;
    std::cout << "set contains 1: " << intSet.Contains(1) << std::endl;
    std::cout << "set contains 40: " << intSet.Contains(40) << std::endl;
    std::cout << "set[0] = " << intSet.Get(0) << std::endl;
    std::cout << "set[1] = " << intSet.Get(1) << std::endl;

    intSet.Clear();
    std::cout << "size: " << intSet.Size() << std::endl;
    std::cout << "set contains 1: " << intSet.Contains(1) << std::endl;
    std::cout << "set contains 40: " << intSet.Contains(40) << std::endl;

    GenericContainers::Set<std::string> stringSet;

    stringSet.Insert("test");
    stringSet.Insert("dog");
    stringSet.Insert("cat");

    std::cout << "size: " << stringSet.Size() << std::endl;
    std::cout << "set contains \"dog\": " << stringSet.Contains("dog") << std::endl;
    std::cout << "set contains \"apple\": " << stringSet.Contains("apple") << std::endl;
    std::cout << "set[0] = " << stringSet.Get(0) << std::endl;
    std::cout << "set[1] = " << stringSet.Get(1) << std::endl;
    std::cout << "set[2] = " << stringSet.Get(2) << std::endl;

    stringSet.Remove("cat");
    std::cout << "size: " << stringSet.Size() << std::endl;
    std::cout << "set contains \"cat\": " << stringSet.Contains("cat") << std::endl;
    std::cout << "set[0] = " << stringSet.Get(0) << std::endl;
    std::cout << "set[1] = " << stringSet.Get(1) << std::endl;

    return 0;
}