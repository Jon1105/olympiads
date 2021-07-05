#include <iostream>

void printN(int center, size_t numBrackets) {
    if (numBrackets == 0) {
        std::cout << center;
    } else {
        std::cout << '[';
        printN(center, numBrackets-1);
        std::cout << ']';
    }
}

int main(int argc, char const *argv[])
{
    int center;
    size_t numBrackets;
    std::cin >> center >> numBrackets;
    printN(center, numBrackets);
    std::cout << '\n';
    return 0;
}
