#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// https://codeforces.com/problemset/problem/455/A
int boredom(unordered_set<int>& integers, const unordered_map<int, int>& points)
{
    const vector<int> ints(integers.begin(), integers.end());
    if (ints.size() == 1) {
        return ints[0] * points.at(ints[0]);
    }
    int integers_size = ints.size();
    int res = 0;
    for (int i = 0; i < integers_size; ++i) {
        int removed = ints[i];
        int removed_points = removed * points.at(removed);
        vector<int> removed_integers;
        if (integers.count(removed - 1)) {
            removed_integers.push_back(removed - 1);
        }
        if (integers.count(removed + 1)) {
            removed_integers.push_back(removed + 1);
        }
        removed_integers.push_back(removed);
        integers.erase(removed - 1);
        integers.erase(removed);
        integers.erase(removed + 1);
        int curr = removed_points + boredom(integers, points);
        if (curr > res) {
            res = curr;
        }
        for (const int ri : removed_integers) {
           integers.insert(ri); 
        }
    }
    return res;
}

int main() 
{
    int n;
    cin >> n;
    int* a = new int[n];
    unordered_map<int, int> points;
    unordered_set<int> integers;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        integers.insert(a[i]);
        ++points[a[i]];
    }
    cout << boredom(integers, points) << std::endl;
    return 0;
}