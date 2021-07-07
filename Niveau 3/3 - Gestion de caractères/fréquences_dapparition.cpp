#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main(int argc, char const *argv[])
{
    std::string entry;
    std::getline(std::cin, entry);
    size_t letter_count{0};
    std::vector<size_t> letter_freq(26, 0);
    for (size_t i = 0; i < entry.size(); i++){
        // std::cout << entry[i] << '\n';
        if (isalpha(entry[i])) {
            // std::cout << "I: " << std::toupper(entry[i])-65 << '\n';
            letter_count ++;
            letter_freq[std::toupper(entry[i])-65] ++;
        }
    }
        // std::cout << "Size: " << letter_freq.size() << '\n';
    for (auto n : letter_freq)
        std::cout << (double)n/letter_count << '\n';
    // for (size_t i = 0; i < 26; i++) {
    //     double n = letter_freq[i] / letter_count;
    //     std::cout << n << '\n';
    // }
    
    return 0;
}
