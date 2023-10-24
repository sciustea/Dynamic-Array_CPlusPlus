#include <iostream>
#include "DynamicArray.cpp"

int main()
{
    DynamicArray<int> DA(10);

    for (int i = 0; i < 20; ++i)
    {
        DA.add(i);
    }

    for (int i = 0; i < 20; ++i)
    {
        std::cout << DA.getByElement(i) << std::endl;
    }

    for (int i = 0; i < 15; ++i)
    {
        DA.removeByElement(10);
    }
    
    for (int i = 0; i < 20; ++i)
    {
        std::cout << DA.getByElement(i) << std::endl;
    }

    return 0;
}