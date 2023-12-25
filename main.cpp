#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


// https://codeforces.com/problemset/problem/455/A
int boredom(vector<int>& integers, unordered_map<int, int>& points)
{
    int integers_size = integers.size();
    int max = 0;
    for (int i = 0; i < integers_size; ++i) {
        int removed = integers[i];
        vector<pair<int, int>> removed_pairs;
        if (points[removed - 1]) {
            removed_pairs.push_back(make_pair(removed - 1, points[removed - 1]));
        }
        if (points[removed + 1]) {
            removed_pairs.push_back(make_pair(removed + 1, points[removed + 1]));
        }
        if (--points[removed] == 0) {
            points.erase(removed);
            removed_pairs.push_back(make_pair(removed, 1));
        }
        integers.erase(integers.begin() + i);
        int res = integers[i];
        integers.insert(integers.begin() + i, removed);
        if (points[removed]) {
            ++points[removed];
        }
        for (const auto& rp : removed_pairs) {
            points[rp.first] = rp.second;
        }
    }
    return 10;
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
    cout << boredom(integers, points) << std::endl;
    return 0;
}