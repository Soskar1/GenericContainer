#include <iostream>
#include "Set.h"

int main()
{
    GenericContainers::Set<int> container;

    container.Create(5);

    container.Destroy();
    return 0;
}