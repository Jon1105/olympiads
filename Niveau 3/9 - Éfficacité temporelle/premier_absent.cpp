#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    size_t n, p;
    std::cin >> n >> p;

    int firstAbsent = 1;
    std::vector<bool> present(n, false);
    for (size_t i = 0; i < p; i++)
    {
        size_t e;
        std::cin >> e;
        present[e - 1] = true;
        if (e > firstAbsent)
        {
            std::cout << firstAbsent << '\n';
        }
        else
        {
            size_t j = firstAbsent - 1;
            for (; j < n; j++)
            {
                if (!present[j])
                {
                    firstAbsent = j + 1;
                    std::cout << firstAbsent << '\n';
                    break;
                }
            }
            if (j == n)
            {
                firstAbsent = -1;
                std::cout << firstAbsent << '\n';
            }
        }
    }

    return 0;
}
