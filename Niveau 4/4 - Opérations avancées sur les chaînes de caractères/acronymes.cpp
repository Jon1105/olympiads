#include <iostream>
#include <string>

int main() {
    // SETUP
    std::string acronyme;
    size_t nbLivres;
    std::cin >> acronyme;
    std::cin >> nbLivres;
    std::cin.ignore();

    // REPEAT FOR EVERY WORD
    for (size_t i = 0; i < nbLivres; i++) {
        // INPUT
        std::string entry{""};
        std::getline(std::cin, entry);

        bool space_before{true}; // WHETHER THE CURRENT LETTER IS THE BEGINNING OF A WORD
        // INITIALIZED AT TRUE SO THAT FIRST WORD IS ALSO RECOGNIZED AS THE BEGINNING
        bool valid{false}; // For when beginning of title matches acronyms, but there are still more words after
        std::string checkAcronyme{""};
        // LOOP THROUGH LETTERS IN TITLE
        for (size_t i = 0; i < entry.size(); i++){
            if (space_before) {
                if (std::tolower(acronyme[checkAcronyme.size()]) != std::tolower(entry[i])) {
                    valid = false;
                    break;
                } else {
                    valid = true;
                    checkAcronyme += std::toupper(entry[i]);
                }
            }
            if (space_before && std::islower(entry[i])) {
                entry[i] = std::toupper(entry[i]);
            } else if (!space_before && std::isupper(entry[i])) {
                entry[i] = std::tolower(entry[i]);
            }
            space_before = entry[i] == ' ';
        }
        if (valid && checkAcronyme == acronyme) {
            std::cout << entry << '\n';
        }
    }
    
    return 0;
}
