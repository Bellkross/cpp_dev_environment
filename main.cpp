#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// https://codeforces.com/problemset/problem/455/A
int boredom(vector<int>& integers, unordered_map<int, int>& points)
{
    if (integers.size() == 1 && points[integers[0]] == 1) {
        return integers[0];
    }
    int integers_size = integers.size();
    int res = 0;
    for (int i = 0; i < integers_size; ++i) {
        int removed = integers[i];
        int removed_points = removed * points[removed];
        vector<pair<int, int>> removed_pairs;
        if (points.count(removed - 1) > 0) {
            removed_pairs.push_back(make_pair(removed - 1, points[removed - 1]));
        }
        if (points.count(removed + 1) > 0) {
            removed_pairs.push_back(make_pair(removed + 1, points[removed + 1]));
        }
        removed_pairs.push_back(make_pair(removed, points[removed]));
        points.erase(removed - 1);
        points.erase(removed);
        points.erase(removed + 1);
        integers.erase(integers.begin() + i);
        int curr = removed_points + boredom(integers, points);
        if (curr > res) {
            res = curr;
        }
        integers.insert(integers.begin() + i, removed);
        for (const auto& rp : removed_pairs) {
            points[rp.first] = rp.second;
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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++points[a[i]];
    }
    vector<int> integers(points.size());
    for (const auto& pair : points) {
        integers.push_back(pair.first);
    }
    sort(integers.begin(), integers.end());
    cout << boredom(integers, points) << std::endl;
    return 0;
}