#include <iostream>
#include "Set.h"
#include "LightweightSet.h"

int main()
{
    GenericContainers::LightweightSet<int> set;

    set.Insert(1);
    set.Insert(2);
    set.Insert(5);
    set.Insert(3);
    set.Insert(4);
    set.Insert(2);

    std::cout << set.Get(0) << std::endl;
    std::cout << set.Get(1) << std::endl;
    std::cout << set.Get(2) << std::endl;
    std::cout << set.Get(3) << std::endl;
    std::cout << set.Get(4) << std::endl;

    std::cout << set.Contains(5) << std::endl;
    std::cout << "size: " << set.Size() << std::endl;

    set.Remove(5);

    std::cout << set.Contains(5) << std::endl;
    std::cout << "size: " << set.Size() << std::endl;

    set.Remove(1);
    std::cout << "size: " << set.Size() << std::endl;
    std::cout << set.Get(0) << std::endl;
    std::cout << set.Get(1) << std::endl;
    std::cout << set.Get(2) << std::endl;

    set.Clear();
    set.Insert(55);
    std::cout << "size: " << set.Size() << std::endl;
    std::cout << set.Get(0) << std::endl;

    set.Insert(2);
    std::cout << "size: " << set.Size() << std::endl;
    std::cout << set.Get(0) << std::endl;
    std::cout << set.Get(1) << std::endl;

    set.Edit(55, 1);
    std::cout << "size: " << set.Size() << std::endl;
    std::cout << set.Get(0) << std::endl;
    std::cout << set.Get(1) << std::endl;

    return 0;
}