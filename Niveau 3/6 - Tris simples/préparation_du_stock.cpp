#include <iostream>
#include <vector>

void print(std::vector<int> v) {
    for (auto &&i : v) 
        std::cout << i << " ";
    std::cout << '\n';
}

int main(int argc, char const *argv[]) {
    size_t n, m;
    std::cin >> n >> m;
    std::vector<int> initial(n);
    std::vector<int> indices(m, 0);
    for (size_t i = 0; i < n; i++)
        std::cin >> initial[i];
    for (size_t i = 0; i < m; i++) {
        // LINE 3
        // read pollution level
        int p;
        std::cin >> p;
        // find index where to insert at
        size_t k = 0;
        // Note: don't use n as size will change
        for (; k < initial.size(); k++) {
            if (p <= initial[k])
                break;
        }
        initial.insert(initial.begin() + k, p);
        indices[i] = k;
    }
    print(indices);
    print(initial);
    
    return 0;
}
