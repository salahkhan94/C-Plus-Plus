#include <iostream>
#include <vector>
#include <map>

std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
{
    std::map<std::string, int> countMap;
		for (auto itr = names1.begin(); itr != names1.end(); itr++) {
			auto result = countMap.insert(std::pair<std::string, int>(*itr, 1));
		}
        for (auto itr = names2.begin(); itr != names2.end(); itr++) {
			auto result = countMap.insert(std::pair<std::string, int>(*itr, 1));
		}
        std::vector<std::string> names;
        for (auto itr = countMap.begin(); itr != countMap.end(); itr++) {
			names.push_back(itr->first);
		}
        return names;
}

#ifndef RunTests
int main()
{
    std::vector<std::string> names1 = {"Ava", "Emma", "Olivia"};
    std::vector<std::string> names2 = {"Olivia", "Sophia", "Emma"};
    
    std::vector<std::string> result = unique_names(names1, names2);
    for(auto element : result)
    {
        std::cout << element << ' '; // should print Ava Emma Olivia Sophia
    }
}
#endif