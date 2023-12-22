#include <iostream>
#include <string>

int main() {
    int watermelon_weight;
    std::cin >> watermelon_weight;
    std::string result = watermelon_weight % 2 == 0 ? "YES" : "NO";
    std::cout << result << std::endl;
    return 0;
}