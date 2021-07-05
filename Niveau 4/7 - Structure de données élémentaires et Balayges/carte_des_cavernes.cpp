#include <iostream>

bool valid(std::string map, size_t n) {
    size_t path = 0;
    for (size_t i = 0; i < n; i++) {
        if (map[i] == '(') {
            path ++;
        } else if (map[i] == ')') {
            if (path <= 0) {
                return false;
            }
            path --;
        }
    }
    return (path == 0);
}

int main(int argc, char const *argv[])
{
    size_t n; std::cin >> n;
    std::string map;
    std::cin.ignore();
    std::getline(std::cin, map);
    std::cout << valid(map, n) << '\n';
    
    return 0;
}
