#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    size_t p, o;
    std::cin >> p;
    std::vector<int> items(p);
    for (size_t i = 0; i < p; i++)
        std::cin >> items[i];
    std::cin >> o;
    for (size_t i = 0; i < o; i++) {
        size_t id;
        int quantite;
        std::cin >> id >> quantite;
        items[id-1] += quantite;
    }

    for (auto &&i : items)
        std::cout << i << ' ';
    std::cout << '\n';
    
    
    return 0;
}
