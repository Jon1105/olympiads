#include <iostream>
#include <vector>

bool get(uint8_t const *present, size_t index)
{
    size_t b = index / 8;
    size_t shift = index % 8;
    return 1 == ((present[b] >> shift) & 1);
}

void set(uint8_t *present, size_t index, bool value)
{
    size_t b = index / 8;
    size_t shift = index % 8;
    present[b] |= (value ? 1 : 0) << shift;
}

int main(int argc, char const *argv[])
{
    size_t n, p;
    std::cin >> n >> p;

    int firstAbsent = 1;
    size_t size = n / 8; // math.ceil(n/8);
    uint8_t present[size]{0};
    for (size_t i = 0; i < p; i++)
    {
        size_t e;
        std::cin >> e;
        set(present, e - 1, true);
        if (e > firstAbsent)
        {
            std::cout << firstAbsent << '\n';
        }
        else
        {
            size_t j = firstAbsent - 1;
            for (; j < n; j++)
            {
                if (!get(present, j))
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
