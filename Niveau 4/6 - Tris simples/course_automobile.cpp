#include <iostream>
#include <vector>

template <typename t>
class pair {
    public:
        t i, j;
        pair(t i, t j) : i{i}, j{j} {};
        friend std::ostream& operator<<(std::ostream& out, const pair& p) {
            out << p.i << " " << p.j << '\n';
            return out;
        }
};

int main(int argc, char const *argv[]) {
    // INPUT AND SETUP
    size_t nbAutomobiles;
    std::cin >> nbAutomobiles;
    std::vector<size_t> automobiles(nbAutomobiles);
    std::vector<pair<size_t>> swappings{};
    for (size_t i = 0; i < nbAutomobiles; i++) 
        std::cin >> automobiles[i];
    // SORTING
    bool done{false};
    while (!done) { // until break 
        done = true;
        for (int i = automobiles.size() - 1; i > 0; i--) {
            if (automobiles[i] < automobiles[i-1]) {
                done = false;
                std::swap(automobiles[i], automobiles[i-1]);
                swappings.push_back(pair<size_t>(automobiles[i], automobiles[i-1]));
            }
        }
    }
    // OUTPUT
    std::cout << swappings.size() << '\n';
    for (auto &&i : swappings) {
        std::cout << i;
    }
    std::cout << "Automobiles: ";
    for (auto &&i : automobiles) {
        std::cout << i;
    }
    return 0;
}
