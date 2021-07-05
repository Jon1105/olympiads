#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compare (std::string a, std::string b) {return a<b;} 

int main()
{
    size_t numEntries;
    std::cin>>numEntries;
    std::vector<std::string> all(numEntries, "");
    for (size_t i = 0; i < numEntries; i++)
    {
        std::string mot1, mot2;
        std::cin >> mot1 >> mot2;
        all[i] = mot2 + " " + mot1;
    }
    std::sort(all.begin(), all.end(), compare);
    for (auto s : all) 
        std::cout << s << '\n';
    return 0;

}

