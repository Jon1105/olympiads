#include <iostream>
#include <string>

int main() {
    std::string key, text;
    std::cin >> key;
    std::cin.ignore();
    std::getline(std::cin, text);

    for (size_t i = 0; i < text.size(); i++) {
        if (std::isalpha(text[i])) {
            if (std::isupper(text[i]))
                text[i] = std::toupper(key[text[i]-65]);
            else if (std::islower(text[i]))
                text[i] = key[text[i]-97];
        }
    }
    
    std::cout << text << '\n';

    return 0;
}
