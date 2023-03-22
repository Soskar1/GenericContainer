#include <iostream>
#include "Set.h"

int main()
{
    GenericContainers::Set<int> set;
    set.Insert(1);
    set.Insert(2);
    set.Insert(3);
    set.Insert(4);
    set.Insert(5);

    std::cout << set.Contains(5) << std::endl;
    std::cout << set.Contains(6) << std::endl;

    set.Edit(5, 6);

    std::cout << set.Contains(5) << std::endl;
    std::cout << set.Contains(6) << std::endl;
    std::cout << "size: " << set.Size() << std::endl;

    set.Clear();

    std::cout << "size: " << set.Size() << std::endl;
    std::cout << set.Contains(1) << std::endl;
    std::cout << set.Contains(2) << std::endl;
    std::cout << set.Contains(3) << std::endl;
    std::cout << set.Contains(4) << std::endl;
    std::cout << set.Contains(5) << std::endl;
    std::cout << set.Contains(6) << std::endl;

    //set.Remove(1);
    //set.Remove(2);
    //set.Remove(3);
    //set.Remove(4);
    //set.Remove(5);

    return 0;
}