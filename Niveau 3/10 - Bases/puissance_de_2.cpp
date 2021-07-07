#include <iostream>

int main(int argc, char const *argv[])
{
    size_t n; std::cin >> n;
    size_t o = 1;
    while (o * 2 <= n) 
        o *= 2;
    std::cout << o << '\n';
    
    return 0;
}
