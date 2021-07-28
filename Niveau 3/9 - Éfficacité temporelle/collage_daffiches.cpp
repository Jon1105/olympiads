#include <forward_list>
#include <iostream>

int main() {
    size_t nbRequetes;
    std::cin >> nbRequetes;
    std::forward_list<size_t> stack{};
    char query;
    size_t height;
    size_t size = 0;

    for (size_t i = 0; i < nbRequetes; i++) {
        std::cin >> query;

        if (query == 'Q') {
            std::cout << size << '\n';
        } else if (query == 'C') {
            std::cin >> height;

            stack.remove_if([height, &size](size_t n) {
                if (n <= height) {
                    size--;
                    return true;
                }
                return false;
            });

            stack.push_front(height);
            size++;
        }
    }

    return 0;
}