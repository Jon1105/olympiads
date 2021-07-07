#include <iostream>
#include <vector>

void recur(std::vector<std::vector<bool>>* image, size_t repeat) {
    if (repeat == 1) 
        return;
        
    auto copy = *image;
    const size_t s = copy.size();
    for (size_t i = 0; i < s; i++) {
        (*image)[i].insert((*image)[i].end(), copy[i].begin(), copy[i].end());
        copy[i].resize(s * 2);
    }
    image->insert(image->end(), copy.begin(), copy.end());
    
    
    return recur(image, repeat/2);
}


int main() {
    size_t size; std::cin >> size;
    if (size == 1) {
        std::cout << '#' << '\n';
        return 0;
    }
    std::vector<std::vector<bool>> image = {
        {true, true},
        {true, false},
    };

    recur(&image, size/2);

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            std::cout << (image[i][j] ? '#' : ' ');
        }
        std::cout << '\n';
    }
    
    return 0;
}
