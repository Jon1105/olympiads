#include <iostream>
#include <vector>
#include <algorithm>

/* Explanation
In this case using std::sort with std::binary_search is much quicker than std::find, because we need to find multiple times. The sorting is done only once, so when n increases, the complexity of the sort becomes smaller in comparison, and binary search is very efficient, rather than continuously iterating over blocs
*/

int main(int argc, char const *argv[]) {
    size_t n; std::cin >> n;
    std::vector<int> blocs(n);
    for (size_t i = 0; i < n; i++)
        std::cin >> blocs[i];

    std::sort(blocs.begin(), blocs.end());
    std::cin >> n;
    for (size_t i = 0; i < n; i++) {
        int demande; std::cin >> demande;
        std::cout << std::binary_search(blocs.begin(), blocs.end(), demande) << '\n';
    }
    return 0;
}