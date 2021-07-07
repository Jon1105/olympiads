#include <iostream>
#include <string>


int main(int argc, char const *argv[])
{
    std::string nom;
    size_t age;
    std::cin >> nom;
    std::cin >> age;


    int batiment = nom[0] - 64;
    char allee = age + 64;

    std::cout << batiment << allee << '\n';

    return 0;
}
