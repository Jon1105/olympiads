#include <iostream>
#include <math.h>

int main(int argc, char const *argv[])
{
    size_t baseDepart, nbChiffres;
    std::cin >> baseDepart >> nbChiffres;
    int num = 0;
    for (size_t i = 0; i < nbChiffres; i++) {
        int n; std::cin >> n;
        num += n * pow(baseDepart, nbChiffres-1-i);
    }
    std::cout << num << '\n';
    return 0;
}

/*
144 12 1
    3  11
*/
