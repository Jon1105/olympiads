#include <iostream>
#include <vector>
#include <algorithm>
int main(int argc, char const *argv[])
{
    size_t n; std::cin >> n;
    std::vector<unsigned int> blocs(n);
    for (size_t i = 0; i < n; i++)
        std::cin >> blocs[i];
    std::sort(blocs.begin(), blocs.end());
    std::cin >> n; // n variable is reused
    for (size_t i = 0; i < n; i++) {
        unsigned int t; std::cin >> t;
        auto bound = std::lower_bound(blocs.begin(), blocs.end(), t);
        // iterator of item greater or equal to t
        unsigned int result;
        if (bound == blocs.begin()) {
            result = *bound;
        } else if (bound == blocs.end()) {
            result = *(bound-1);
        } else if (*bound == t) {
            result = *bound;
        } else if ((*bound - t) < (t - *(bound-1))) {
            result = *bound;
        } else {
            result = *(bound-1);
        }
        std::cout << result << '\n';
        
    }
    return 0;
}