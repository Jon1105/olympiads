#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    size_t n, m;
    std::cin >> n >> m;
    std::vector<int> pollutants(n);

    for (size_t i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        if (pollutants.size() == 0)
            pollutants.push_back(a);
        size_t j = 0;
        for (; j < pollutants.size(); j++) {
            if (a > pollutants[j])
                break;
        }
        pollutants.insert(pollutants.begin() + j, a);
    }

    for (size_t i = 0; i < m; i++)
    {
        std::cout << pollutants[i] << " ";
    }
    std::cout << '\n';
    
    return 0;
}
