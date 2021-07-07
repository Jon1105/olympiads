#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<bool>> erosion(std::vector<std::vector<bool>> image, size_t times) {
    if (times == 0) 
        return image;
    auto copy(image);
    for (size_t i = 0; i < image.size(); i++) {
        bool remove = i == 0 || i == image.size() - 1;
        for (size_t j = 0; j < image[i].size(); j++) {
             bool black = image[i][j] && !(remove || j == 0 || j == (image)[i].size() - 1) && (image)[i-1][j] && (image)[i+1][j] && (image)[i][j-1] && (image)[i][j+1];
             copy[i][j] = black;
        }
        // std::cout << '\n';
    }
    return erosion(copy, times-1);
}

int main(int argc, char const *argv[])
{
    size_t n, h ,l;
    std::cin >> n >> h >> l;
    std::cin.ignore();

    std::vector<std::vector<bool>> image(h, std::vector<bool>(l));

    for (size_t i = 0; i < h; i++)
    {
        std::string line{};
        std::getline(std::cin,line);
        for (size_t j = 0; j < l; j++) {
            image[i][j] = line[j] == '#';
        }
    }

    auto v = erosion(image, n);
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[i].size(); j++)
        {
            std::cout << (v[i][j] ?  '#' : '.');
        }
        std::cout << '\n';
        
    }
    
    return 0;
}
