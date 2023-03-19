#include <iostream>
#include "Set.h"

int main()
{
    GenericContainers::Set<int> container;

    container.Create(5);

    std::cout << container.Size() << std::endl;

    container.Insert(6);

    std::cout << container.Size() << std::endl;

    int a = container.Get(1);

    return 0;
}