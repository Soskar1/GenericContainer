#include <iostream>
#include "Set.h"

int main()
{
    GenericContainers::Set<int> container;

    container.Create(5);

    std::cout << container.Size() << std::endl;

    container.Insert(6);

    std::cout << container.Size() << std::endl;

    container.Destroy();
    return 0;
}