#include <iostream>
#include <string>
#include <cctype>

bool valid(std::string entry) {
    if (!(isalpha(entry[0]) || entry[0] == '_')) {
        return false;
    }
    for (size_t i = 1; i < entry.size(); i++) {
        if (!(isalpha(entry[i]) || isdigit(entry[i]) || entry[i] == '_')) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    size_t numEntries;
    std::cin>>numEntries;
    std::cin.ignore();
    for (size_t i = 0; i < numEntries; i++)
    {
        // count ++;
        std::string entry;
        std::getline(std::cin, entry);
        // std::cin.ignore(); // ignore '\n' from the input stream
        // std::remove_if(entry.begin(), entry.end(), ::isspace);
        if (valid(entry))
            std::cout << "YES" << '\n';
        else
            std::cout << "NO" << '\n';
        // std::cout << valid(entry) ? "YES" : "NO" << '\n';


    }
    return 0;
}
