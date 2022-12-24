#include <vector>
#include <cstddef>

template <typename T>
bool BinarySearch(std::vector<T> list, T item)
{
    std::size_t low = 0;
    std::size_t high = list.size() - 1;

    while (low <= high)
    {
        std::size_t mid = (low + high) / 2;
        T guess = list[mid];

        if (guess == item)
        {
            return true;
        }

        if (guess < item)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}

template bool BinarySearch(std::vector<int> list, int item);
