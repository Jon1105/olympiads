#include <iostream>
#include <bitset>

int main(int argc, char const *argv[])
{
    size_t n; std::cin >> n;
    size_t o = 1;
    while (n >= o*2) 
        o *= 2;
    if (o == 1) {
        if (n == 0) 
            std::cout << 0;
        else if (n == 1) 
            std::cout << 1;
        return 0;
    }
    while (o > 0) {
        if (n >= o) {
            std::cout << 1;
            n -= o;
        } else {
            std::cout << 0;
        }
        o /= 2;
    }
    std::cout << '\n';
    return 0;
}
