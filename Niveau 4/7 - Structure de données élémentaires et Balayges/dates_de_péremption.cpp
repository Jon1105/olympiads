#include <iostream>
#include <stack>

int main(int argc, char const *argv[]) {
    size_t o; std::cin >> o;
    std::stack<size_t> pile;
    for (size_t i = 0; i < o; i++) {
        int n, date;
        std::cin >> n >> date;
        // WARNING: Compiler error
        // Comparison between signed and unsigned data types! (i, n)
        if (n < 0) {
            for (size_t i = 0; i < -n; i++)
                pile.pop();
        } else if (date != 0) {
            for (size_t i = 0; i < n; i++)
                pile.push(date);
        }
    }
    size_t smallest = pile.top();
    pile.pop();
    while (!pile.empty()) {
        if (pile.top() < smallest)
            smallest = pile.top();
        pile.pop();
    }
    
    std::cout << smallest << '\n';
    
    return 0;
}
