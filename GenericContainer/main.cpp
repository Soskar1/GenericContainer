#include <iostream>
#include "Set.h"

int main()
{
    GenericContainers::Set<int> container;

    container.Create(5);

    std::cout << container.Size() << std::endl;

    container.Insert(6);

    container.Insert(7);

    std::cout << container.Size() << std::endl;

    int a = container.Get(2);

    std::cout << a;

    return 0;
}