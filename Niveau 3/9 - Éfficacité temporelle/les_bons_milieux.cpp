#include <iostream>
#include <vector>

struct point {
    size_t x, y;
    point(size_t xVal, size_t yVal) { x = xVal; y = yVal; }
};


int main(int argc, char const *argv[]) {
    size_t nbPoints; std::cin >> nbPoints;
    std::vector<point> points(nbPoints);
    std::vector<std::vector<bool> > _points(101);

    for (size_t i = 0; i < nbPoints; i++) {
        size_t x, y;
        std::cin >> x >> y;
        points[i] = point(x, y);
    }
    
    for (size_t i = 0; i < nbPoints; i++) {
        size_t x, y;
        std::cin >> x >> y;
        points[i] = point(x, y);
    }

    return 0;
}
