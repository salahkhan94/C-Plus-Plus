#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
{
    std::pair<int, int> indices;
    indices.first = -1;
    indices.second = -1;
    std::vector<int> s_list = list;
    
    for(int i=0;i<list.size();i++){
        auto it2 = find(list.begin(),list.end(),(sum-list[i]));
        
        if (it2 != list.end() && i!=(it2-list.begin())){
            indices.first = i;
            indices.second = it2-list.begin();
            break;
        }
    }
    return indices;
    
}


#ifndef RunTests
int main()
{
    std::vector<int> list = {3, 1, 5, 7, 5, 9};
    std::pair<int, int> indices = findTwoSum(list, 10);
    std::cout << indices.first << '\n' << indices.second;
}
#endif

