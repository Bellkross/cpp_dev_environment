#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// 1 - no
// 2 - no
// 3 - no
// 4 - 2 2
// 5 - no
// 6 - 2 4
// 10 - 8 and 2 yes
bool can_divide_in_even_number_of_kilos(const int w)
{
    if (w < 4)
    {
        return false;
    }
    return w % 2 == 0;
}

int main()
{
    int w;
    cin >> w;
    cout << (can_divide_in_even_number_of_kilos(w) ? "YES" : "NO") << endl;
    return 0;
}
