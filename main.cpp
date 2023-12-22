#include <iostream>
#include <string>

int boredom(int* arr, int length)
{
    return 10;
}

int main() 
{
    int n;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::cout << boredom(a, n) << std::endl;
    return 0;
}