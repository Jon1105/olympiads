#include <iostream>

void print(int n, int m) {
    if (n > m) {
        return;
    }
    std::cout << n << ' ';
    return print(n+1, m);
}

int main(int argc, char const *argv[])
{
    int n, m; std::cin >> n >> m;
    print(n, m);
    return 0;
}
