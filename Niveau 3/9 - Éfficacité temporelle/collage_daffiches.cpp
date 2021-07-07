#include <iostream>
#include <forward_list>

size_t size = 0;
size_t height = 0;

int main(int argc, char const *argv[]) {
    
    size_t nbRequetes; std::cin >> nbRequetes;
    std::forward_list<size_t> stack{};
    for (size_t i = 0; i < nbRequetes; i++) {
        char query; std::cin >> query;
        if (query == 'Q') {
            std::cout << size << '\n';
        } else if (query == 'C') {
            std::cin >> height;
            stack.remove_if([](size_t n) {
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
