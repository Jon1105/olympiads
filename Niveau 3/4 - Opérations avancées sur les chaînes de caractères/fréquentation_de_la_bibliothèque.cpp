#include <iostream>

int main(int argc, char const *argv[])
{
    int sum{0};
    while (!std::cin.fail()) {
        int n{0};
        std::cin >> n;
        sum += n;
    }
    std::cout << sum << '\n';
    return 0;
}
