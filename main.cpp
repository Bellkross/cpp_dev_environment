#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;



int main() 
{
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        if (a + b + c >= 2)
        {
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}