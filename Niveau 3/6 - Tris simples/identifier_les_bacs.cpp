#include <iostream>
#include <vector>
#include <algorithm>

struct bac {
    public:
        size_t id, nivPollution;
        bac(size_t id, size_t nivPollution) : id{id}, nivPollution{nivPollution}{};
};


int main(int argc, char const *argv[])
{
    size_t nbBacs; std::cin >> nbBacs;
    std::vector<bac> bacs(nbBacs, bac(0, 0));
    for (size_t i = 0; i < nbBacs; i++) {
        size_t id, nivPollution;
        std::cin >> id >> nivPollution;
        bacs[i] = bac(id, nivPollution);
    }
    std::sort(bacs.begin(), bacs.end(), [](const bac& l, const bac& r) {
        if (l.nivPollution < r.nivPollution)
            return true;
        else if (l.nivPollution == r.nivPollution)
            return l.id < r.id;
        return false;
    });

    for (auto &&i : bacs) 
        std::cout << i.id << ' ' << i.nivPollution << '\n';
    
    return 0;
}
