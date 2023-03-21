#include <iostream>
#include "Set.h"

int main()
{
    GenericContainers::Set<int> set;

    set.Insert(7);

    std::cout << "size: " << set.Size() << std::endl;

    set.Insert(6);
    set.Insert(5);

    std::cout << "size: " << set.Size() << std::endl;

    int a = set.Get(0);
    std::cout << "set[0] = " << a << std::endl;

    set.Remove(5);
    std::cout << "size: " << set.Size() << std::endl;
    std::cout << "set[0] = " << set.Get(0) << std::endl;
    std::cout << "set[1] = " << set.Get(1) << std::endl;

    set.Remove(6);
    std::cout << "size: " << set.Size() << std::endl;
    std::cout << "set[0] = " << set.Get(0) << std::endl;

    set.Remove(8);
    std::cout << "size: " << set.Size() << std::endl;
    std::cout << "set[0] = " << set.Get(0) << std::endl;

    return 0;
}