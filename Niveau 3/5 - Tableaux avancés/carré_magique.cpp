#include <iostream>
#include <vector>
// #define DEBUG

int sumRow(const size_t size, std::vector<int>* row) {
    int total{0};
    for (size_t i = 0; i < size; i++) {
        total += (*row)[i];
    }
    return total;
}

int sumColumn(const size_t size, std::vector<std::vector<int>>* square, const size_t colNum) {
    int total{0};
    for (size_t i = 0; i < size; i++) {
        total += (*square)[i][colNum];
    }
    return total;    
}

int sumDiagonal1(const size_t size, std::vector<std::vector<int>>* square) {
    int total{0};
    for (size_t i = 0; i < size; i++) {
        total += (*square)[i][i];
    }
    return total;    
}

int sumDiagonal2(const size_t size, std::vector<std::vector<int>>* square) {
    int total{0};
    for (size_t i = 0; i < size; i++) {
        total += (*square)[i][size-i-1];
    }
    return total;    
}

int main(int argc, char const *argv[]) {
    size_t size;
    std::cin >> size;
    std::vector<std::vector<int>> carre(size, std::vector<int>(size, 0));
    bool check[size*size] = {false};
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            std::cin >> carre[i][j];
            if (check[carre[i][j]-1] == false) {
                check[carre[i][j]-1] = true;
            } else { // already set to true and therefore there is twice of the same number
                #ifdef DEBUG
                std::cout << "no1" << '\n';
                #else
                std::cout << "no" << '\n';
                #endif
                return 0;
                
            }

        }
    }

    for (auto i : check)
    {
        if (!i) {
            #ifdef DEBUG
            std::cout << "no2" << '\n';
            #else
            std::cout << "no" << '\n';
            #endif
            return 0;
        }
    }
    
    // PRINT SQUARE
    // for (size_t i = 0; i < size; i++) {
    //     for (size_t j = 0; j < size; j++) {
    //         std::cout << carre[i][j] << " ";
    //     }
    //     std::cout << '\n';
    // }

    int sum = sumDiagonal2(size, &carre);
    // std::cout << sum << '\n';
    for (size_t i = 0; i < size; i++) {
        if (sumRow(size, &carre[i]) != sum || sumColumn(size, &carre, i) != sum) {
            #ifdef DEBUG
            std::cout << "no3" << '\n';
            #else
            std::cout << "no" << '\n';
            #endif
            return 0;
        }
    }
    if (sumDiagonal1(size, &carre) != sum) {
        #ifdef DEBUG
        std::cout << "no4" << '\n';
        #else
        std::cout << "no" << '\n';
        #endif
        return 0;
    }

    std::cout << "yes" << '\n';
    return 0;
}