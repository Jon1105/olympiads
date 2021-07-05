#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    char in[10001];
    std::cin.getline(in, sizeof(in));
    for (size_t i = 0; i < std::strlen(in); i++){
        if ((char)in[i] <=122 && (char)in[i] >= 97)
            in[i] = in[i] - 'a' + 'A';
    }
    std::cout << in << '\n';
    return 0;
}
