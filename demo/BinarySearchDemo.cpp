#include <iostream>
#include <vector>

#include "GrokkingAlgorithms.h"

void PrintBinarySearch(const std::vector<int>& list, int item, bool isFound)
{
    std::cout << "Binary Search Demo: " << std::endl;

    std::cout << "\t List: ";
    for (auto i : list)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "\t Item: " << item << std::endl;

    std::cout << "\t Is Found: " << isFound << std::endl;
}

void BinarySearchDemo()
{
    std::vector<int> list;
    int item = 0;
    bool isFound = false;

    list = { 1, 3, 5, 7, 9 };
    item = 3;
    isFound = BinarySearch(list, item);
    PrintBinarySearch(list, item, isFound);

    list = { 2, 4, 6, 8, 10 };
    item = 3;
    isFound = BinarySearch(list, item);
    PrintBinarySearch(list, item, isFound);
}