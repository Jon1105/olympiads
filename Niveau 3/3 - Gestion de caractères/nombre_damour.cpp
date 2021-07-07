#include <iostream>
#include <string>

int sumOfDigits(int num) {
    if (num < 10) {
        return num;
    }
    int rem{0}, sum{0};
    while (num > 0) {
        rem = num%10;
        sum += rem;
        num /= 10;
    }
    return sumOfDigits(sum);
}

int nombreDamour(std::string name) {
    int nombre{0};
    for (char n: name) {
        nombre += n-65;
    }
    return sumOfDigits(nombre);
}

int main(int argc, char const *argv[]) {
    std::string name1, name2;
    std::cin >> name1 >> name2;

    std::cout << nombreDamour(name1) << " " << nombreDamour(name2) << '\n';
    return 0;
}
