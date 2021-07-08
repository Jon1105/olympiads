#include <iostream>
#include <vector>

int main() {
  size_t num, base;
  std::cin >> num >> base;
  std::vector<size_t> res{};
  size_t count = 1;
  while (num >= base) {
    res.push_back(num % base);
    num = num / base;
    count++;
  }
  res.push_back(num);
  std::cout << count << '\n';
  for (auto i = res.rbegin(); i != res.rend(); ++i) {
    std::cout << *i << ' ';
  }
    
  std::cout << '\n';
}
