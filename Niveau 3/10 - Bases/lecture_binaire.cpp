#include <iostream>

int main(int argc, char const *argv[])
{
    std::string in; std::getline(std::cin, in);
    std::cout << stoi(in, 0, 2);
    return 0;
}
