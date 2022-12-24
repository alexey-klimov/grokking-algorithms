#include "kisstest.h"
#include "GrokkingAlgorithms.h"

void BinarySearchTest()
{
    std::vector<int> list;
    int item = 0;
    bool isFound = false;

    list = { 1, 3, 5, 7, 9 };
    item = 3;
    isFound = BinarySearch(list, item);
    KISSTEST::ASSERT(isFound);

    list = { 2, 4, 6, 8, 10 };
    item = 3;
    isFound = BinarySearch(list, item);
    KISSTEST::ASSERT(!isFound);
}

void RunBinarySearchTests()
{
    KISSTEST::RUN_TEST(BinarySearchTest);
}