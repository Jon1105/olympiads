#include <iostream>
#include <string>

void print(std::string n, size_t size) {
    if (size == 0) 
        return;
    std::cout << n[size-1];
    return print(n, size-1);
}

int main(int argc, char const *argv[])
{
    std::string entry;
    std::getline(std::cin, entry);
    print(entry, entry.size());
    return 0;
}
