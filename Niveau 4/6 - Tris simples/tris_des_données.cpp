#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    size_t n;
    std::cin >> n;
    std::vector<size_t> bacs{};
    size_t temp; std::cin >> temp; bacs.push_back(temp);
    for (size_t i = 1; i < n; i++) {
        size_t a;
        std::cin >> a;
        size_t j = 0;
        for (; j < bacs.size(); j++) {
            if (a <= bacs[j])
                break;
        }
        bacs.insert(bacs.begin() + j, a);
    }
    
    for (auto &&i : bacs)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}
