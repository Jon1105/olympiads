#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char const *argv[])
{
    size_t n; std::cin >> n;
    std::vector<std::string> all(n);
    for (size_t i = 0; i < n; i++)
        std::cin >> all[i];
    std::sort(all.begin(), all.end());
    for (auto &&i : all)
        std::cout << i << '\n';
    return 0;
}
