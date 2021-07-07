#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool isPalindrome(std::string entry) {
    size_t size = entry.size();
    if (size <= 1) {
        return true;
    }
    if (entry[0] == ' ') {
        auto n = entry.substr(1, size-1);
        // std::cout << n << '\n';
        return isPalindrome(n);
    }
     if (entry[size-1] == ' ') {
        auto n = entry.substr(0, size-1);
        // std::cout << n << '\n';
        return isPalindrome(n);
    }
     if (std::tolower(entry[0]) == std::tolower(entry[size-1])) {
        return isPalindrome(entry.substr(1, size-2));
    }
    return false;
}

int main(int argc, char const *argv[])
{
    // int count{0};
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
        if (isPalindrome(entry)) {
            std::cout << entry << '\n';
        }

    }

    // std::cout << "Count: " << count << '\n';
    
    return 0;
}
