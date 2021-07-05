#include <iostream>

std::string printN(size_t n) {
    if (n == 0) {
        return "0";
    } else {
        return "(" + printN(n-1) + " + "  + printN(n-1) + ")";
    }
}

int main(int argc, char const *argv[])
{
    size_t n; std::cin >> n;
    std::cout << "0 = " << printN(n) << '\n';
    return 0;
}

