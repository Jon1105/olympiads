#include <iostream>
#include <vector>

size_t nbMesures;
double diffMax;
std::vector<double> mesures;

bool valid(std::vector<double> n) {
    for (size_t i{0}; i < n.size(); i++) {
        if (abs(n[i]-n[i-1]) > diffMax) {
            return false;
        }
    }
    return true;
}

double absolute(double n) {
    if (n < 0)
        return -n;
    return n;
}

int recur(std::vector<double> n) {
    bool isValid = true;
    std::vector<double> modified{n}; // make a copy of n
    for (size_t i{1}; i < n.size(); i++) {
        if (i != n.size() - 1) {
            modified[i] = (n[i-1] + n[i+1])/2;
        }
        isValid = isValid && (absolute(modified[i-1]-modified[i]) <= diffMax);
    }
    if (isValid)
        return 1;
    else 
        return 1 + recur(modified);
}

int main(){
    std::cin >> nbMesures;
    std::cin >> diffMax;
    float mesure;
    for (size_t i = 0; i < nbMesures; i ++) {
        std::cin >> mesure;
        mesures.push_back(mesure);
    }

    // RUN

    if (valid(mesures) || mesures.size() < 3)
        std::cout << 0 << std::endl;
    else
        std::cout << recur(mesures) << std::endl;
    return 0;
}
