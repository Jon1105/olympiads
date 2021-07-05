#include <iostream>
#include <vector>

size_t sumcolumn(std::vector<std::vector<size_t>> &matrix, size_t col) {
    size_t total{0};
    for (size_t i = 0; i < matrix.size(); i++)
    {
        total += matrix[i][col];
    }
    return total;
}

size_t sumdiagonal(std::vector<std::vector<size_t>> &matrix, bool forward=true) {
    size_t total{0};
    if (forward) {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            total += matrix[i][i];
        }
    } else {
        for (size_t i = matrix.size()-1; i >=0; i--)
        {
            total += matrix[i][i];
        }
    }
    return total;
}

size_t sumrow(std::vector<size_t> &n) {
    size_t sum{0};
    for (auto &&i : n)
    {
        sum += i;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    size_t n;
    std::cin >> n;
    std::vector<std::vector<size_t>> carre(n, std::vector<size_t>(n, 0));
    size_t a;
    std::vector<bool> check(n*n, false);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++)
        {
           std::cin >> a;
           carre[i][j] = a;
           check[a-1] = true;
        }
    }
    // check all numbers included
    for (auto i : check) {
        if (!i) {
            std::cout << "no\n";
            return 0;
        }
    }
    
    // check rows are equal
    size_t s = sumrow(carre[0]);
    for (size_t i = 1; i < n; i++) {
        if (s != sumrow(carre[i])) {
            std::cout << "no\n";
            return 0;
        }  
    }

    for (size_t i = 0; i < n; i++)
    {
        if (s != sumcolumn(carre, i)) {
            std::cout << "no\n";
            return 0;
        }
    }
    if (s!=sumdiagonal(carre) || s != sumdiagonal(carre, false)) {
        std::cout<< "no\n";
        return 0;
    }
    
    
    std::cout << "yes\n";
    return 0;
}