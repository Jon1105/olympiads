#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    char input[10000];
    std::cin.getline(input, sizeof(input));
    int letters[26]{0};
    for (size_t i = 0; i < std::strlen(input); i++){
        if (input[i] >= 97 && input[i] <=122)
            letters[input[i]-97] ++;
        else if (input[i] >= 65 && input[i] <= 90)
            letters[input[i]-65] ++;
    }
    int max = 0;
    for (size_t i = 1; i < 26; i++){
        if (letters[i] > letters[max])
            max = i;
    };

    std::cout << (char)(max+65) << '\n';
    return 0;
}
