#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

    }
};

int main()
{
    stringstream ss;
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        long long k;
        cin >> k;
        unordered_map<long long, long long> count;
        // find first that in below set
        for (long long j = 0; j < k; ++j)
        {
            long long curr;
            cin >> curr;
            ++count[curr];
        }
        const long long tar = k - 2;
        if (count[1] > 0 && count[tar] > 0)
        {
            ss << 1 << " " << tar << endl;
            continue;
        }
        for (long long q = 2; q < tar; ++q)
        {
            if (tar % q == 0)
            {
                ss << tar / q << " " << q << endl;
                break;
            }
        }
    }

    cout << ss.str() << endl;

    return 0;
}
