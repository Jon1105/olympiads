#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    size_t n;
    std::cin >> n;
    std::vector<int> bacs(n);
    for (size_t i = 0; i < n; i++) 
        std::cin >> bacs[i];
    
    std::sort(bacs.begin(), bacs.end());

    for (auto &&i : bacs) 
        std::cout << i << ' ';
    
    std::cout << '\n';
    return 0;
}
