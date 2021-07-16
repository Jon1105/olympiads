#include <iostream>
#include <list>
size_t height;
char query;
size_t size;

int main()
{
    size_t nbRequetes;
    std::cin >> nbRequetes;
    std::list<size_t> stack{};
    for (size_t i = 0; i < nbRequetes; i++)
    {
        std::cin >> query;
        if (query == 'Q')
        {
            if (stack.empty())
            {
                size = 0;
            }
            else
            {
                size = 1;
                size_t max = stack.front();

                for (auto i = ++stack.begin(); i != stack.end(); i++)
                {
                    if (*i > *stack.begin() && *i > max)
                    {
                        size++;
                        max = *i;
                    }
                    else
                    {
                        stack.erase(i);
                    }
                }
            }
            std::cout << size << '\n';
        }
        else if (query == 'C')
        {
            std::cin >> height;
            stack.push_front(height);
        }
    }
}
