#include <array>
#include <iostream>

template<typename T, std::size_t N>
void printArray(const std::array<T, N>& arr)
{
    bool first{ true };

    std::cout << "The array (";
    for (const auto& c : arr)
    {
        std::cout << (first ? "" : ", ");
        std::cout << c;
        first = false;
    }
    std::cout << ") has length " << std::ssize(arr);
    std::cout << "\n";
}

int main()
{
    constexpr std::array arr1{ 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2{ 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}
