#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    size_t nbPages;
    std::cin >> nbPages;
    std::cin.ignore();

    for (size_t page = 2; page < nbPages+1; page++) {
        std::string text;
        std::getline(std::cin, text);
        int cle;
        if (page % 2 == 0) {
            cle = 3 * page;
        } else {
            cle = -5 * page;
        }
        while (cle > 26) {
            cle -= 26;
        }
        while (cle < -26) {
            cle += 26;
        }

        for (size_t i = 0; i < text.size(); i++) {
            if (text[i] >= 65 && text[i] <= 90) {
                if (text[i] - cle < 65) {
                    std::cout << (char)(text[i]-cle+26);
                } else if(text[i] - cle > 90) {
                    std::cout << (char)(text[i]-cle-26);
                } else {
                    std::cout << (char)(text[i]-cle);
                }
            } else if (text[i] >= 97 && text[i] <= 122) {
                if (text[i] - cle < 97) {
                    std::cout << (char)(text[i]-cle+26);
                } else if (text[i]-cle > 122) {
                    std::cout << (char)(text[i]-cle-26);
                } else {
                    std::cout << (char)(text[i]-cle);
                }
            } else {
                std::cout << (char)text[i];
            }
        }
        std::cout << '\n';
        

    }
    return 0;
}
