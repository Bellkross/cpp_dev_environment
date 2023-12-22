#include <iostream>
#include <string>

int main() 
{
    std::string line;
    std::getline(std::cin, line);
    char curr;
    int count = 0;
    for (const char& c : line) 
    {
        if (count == 0)
        {
            curr = c;
            count = 1;
            continue;
        }
        if (curr == c)
        {
            ++count;
        } else 
        {
            curr = c;
            count = 1;
        }
        if (count >= 7)
        {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }
    std::cout << "NO" << std::endl;
    return 0;
}