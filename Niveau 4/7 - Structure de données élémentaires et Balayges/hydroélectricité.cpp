#include <iostream>

size_t sum(size_t* river, size_t start, size_t end) {
    size_t sum = 0;
    for (; start <= end; start++) 
        sum += river[start];
    return sum;
}

int main(int argc, char const *argv[])
{
    size_t k, n; std::cin >> k >> n;
    size_t river[n]{}; // { 3 2 5 7 4 2 3 8 4 }
    size_t max = 0;
    size_t previous = 0;
    for (size_t i = 0; i < n; i++) {
        std::cin >> river[i];
        if (i == k-1) {
            previous = sum(river, 0, k-1);
            max = previous;
        } else if (i > k-1) {
            previous = previous - river[i-k] + river[i];
            // size_t v = sum(river, i-(k-1), i+1);
            if (previous > max)
                max = previous;
        }
    }
    std::cout << max << '\n';
    
    return 0;
}

/* 
n=9
k=3
i=0 1 2 3 4 5 6 7 8
{ 3 2 5 7 4 2 3 8 4 }
*/
