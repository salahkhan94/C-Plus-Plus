#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
    auto it = std::lower_bound(sortedVector.begin(), sortedVector.end(), lessThan);
    return (it - sortedVector.begin());
}

#ifndef RunTests
int main()
{
    std::vector<int> v { 1, 3, 5, 7 };
    std::cout << countNumbers(v, 4);
}
#endif