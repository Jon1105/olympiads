#include <iostream>
#include <unordered_map>

int find_duplicate(size_t n) {
    std::unordered_map<size_t, size_t> map{};
    for (size_t i = 0; i < n; i++) {
        size_t t; std::cin >> t;
        if (map.count(t) == 0) {
            map[t] = 1;
        } else { // map.count() == 1
            return t;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    size_t n; std::cin >> n;
    // std::vector<size_t> entries(n);
    std::cout << find_duplicate(n) << '\n';
    
    return 0;
}
