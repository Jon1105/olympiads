// http://www.france-ioi.org/algo/task.php?idChapter=565&idTask=368

#include <iostream>
#include <math.h>
#include <vector>

int main(int argc, char const *argv[])
{
    size_t b1, b2, c;
    std::cin >> b1 >> b2 >> c;
    size_t num = 0;
    for (size_t i = 0; i < c; i++) {
        size_t n; std::cin >> n;
        num += n * pow(b1, c-1-i);
    }// c in decimal

    std::vector<size_t> res{};
    while (num >= b2) {
        res.push_back(num % b2);
        num = num / b2;
    }
    res.push_back(num);
    for (auto i = res.rbegin(); i != res.rend(); ++i) {
        std::cout << *i << ' ';
    }
    return 0;
}
